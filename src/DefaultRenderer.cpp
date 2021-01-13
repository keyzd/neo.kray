#include <stdint.h>
#include <math.h>

#include "utils/List.h"
#include "utils/Pair.h"
#include "DefaultRenderer.h"
#include "ShadeRecord.h"

Vec3 FindAverage( List<Vec3> vecs );

DefaultRenderer::DefaultRenderer() {
	aaSamplesCount = 8;
	for( uint32_t i = 0; i < aaSamplesCount; i++ ) {
		real_t dX = ( drand48() * 2.0 - 1.0 ) * 0.0015;
		real_t dY = ( drand48() * 2.0 - 1.0 ) * 0.0015;
		Pair<real_t, real_t> params;
		params.SetPair( dX, dY );
		aaParams.Push( params );
	}
}

void DefaultRenderer::MakeImage( Canvas& canvas, const Scene& scene, const Camera& camera ) {
	srand48( time( NULL ) );

	int recDepth = 2;

	for( uint32_t x = 0; x < canvas.GetWidth(); x++ ) {
		for( uint32_t y = 0; y < canvas.GetHeight(); y++ ) {
			Vec3 color;
			List<Vec3> primaryRaySamples;

			for( uint32_t i = 0; i < aaSamplesCount; i++ ) {
				real_t dX = aaParams[ i ].el1;
				real_t dY = aaParams[ i ].el2;

				Ray ray = camera.GetRay( x, y );
				ray.SetDirection( camera.ApplyRotations( ray ) );

				Vec3 sample( ray.GetDirection().x + dX, ray.GetDirection().y + dY, ray.GetDirection().z );
				ray.SetDirection( sample );

				color = RayTrace( ray, scene, camera, recDepth );
				primaryRaySamples.Push( color );
			}

			canvas.SetPixel( FindAverage( primaryRaySamples ), x, y );
			primaryRaySamples.ResetCount();
		}
	}
}

// 1. Find closest object for current ray (need cache of hits)
// 2. Find intersection point (from cache of hits) and normal for closest object
// 3. Calculate color
Vec3 DefaultRenderer::RayTrace( const Ray& ray, const Scene& scene, const Camera& camera, int RecDepth ) {
	real_t lenMin;
//	if( RecDepth < 5 )
//		lenMin = 0.7;
//	else
		lenMin = camera.GetProjPlaneDistance();

	Object* closestObject = FindClosestObject( ray, scene, camera, lenMin,
											   INFINITY );
	if( closestObject == NULL ) { 
		return scene.GetBackgroundColor();
	}

	Vec3 intersectedVec;
	closestObject->Intersect( ray, intersectedVec );
	Vec3 normal = closestObject->NormalAt( intersectedVec );
	Vec3 localColor = CalculateLight( camera, scene, normal, intersectedVec, closestObject->material );

	float r = closestObject->material->reflective;
	if( RecDepth <= 0 || r <= 0 )
		return localColor;
	
	Vec3 minusD = Vec3( 0 ) - ray.GetDirection();
	Vec3 reflectedD = minusD.Reflect( normal );
	RecDepth--;
	Ray reflectedRay( intersectedVec, reflectedD );
	
	Vec3 reflectedColor = RayTrace( reflectedRay, scene, camera, RecDepth );
	return localColor*(1.0-r) + reflectedColor*r;
}

Vec3 DefaultRenderer::CalculateLight( const Camera& camera, const Scene& scene, const Vec3& normal,
							   		  const Vec3& hitPoint, Material* objectMaterial ) {
	Vec3 resultColor( 0 );

	for( uint32_t i = 0; i < scene.CountLight(); i++ ) {
		Light* light = scene.GetLightPtr( i );

		if( light->GetType() == LightType::ambient ) {
			resultColor = resultColor + objectMaterial->GetSurfaceColor() * light->GetIntensity();
		} else {
			Vec3 toLightDir;
			real_t lenMin, lenMax;
			lenMin = 0.001;
			Vec3 toCamDir = camera.GetOrigin() - hitPoint;

			if( light->GetType() == LightType::point ) {
				toLightDir = ( light->GetLightPosition() - hitPoint );
				lenMax = toLightDir.Length();
			} else { // directional light
				toLightDir = ( light->GetLightDirection() * -1 );
				lenMax = INFINITY;
			}

			// Shadow
			Ray shadowRay( hitPoint + normal * 0.01, toLightDir );
			if( FindClosestObject( shadowRay, scene, camera, lenMin, lenMax ) != NULL ) {
				continue;
			}

			ShadeRecord shadeRec;
			shadeRec.normal = normal;
			shadeRec.hitPoint = hitPoint;
			shadeRec.toLightDir = toLightDir;
			shadeRec.toCamDir = toCamDir;
			shadeRec.light = light;

			resultColor += objectMaterial->Shade( shadeRec );
		}
	}

	return resultColor;
}

Object* DefaultRenderer::FindClosestObject( const Ray& ray, const Scene& scene, const Camera& camera,
						   			 real_t lenMin, real_t lenMax) {
	long long indexClosest = -1;
	Vec3 closestVec, intersectedVec;
	real_t closestLen = INFINITY;

	for( uint32_t i = 0; i < scene.CountObjects(); i++ ) {
		if( scene.GetObjectPtr( i )->Intersect( ray, intersectedVec ) ) {
			real_t len = intersectedVec.Length();
			if( len < closestLen && len > lenMin && len < lenMax ) {
				indexClosest = i;
				closestLen = len;
			}
		}
	}

	if( indexClosest == -1 ) {
		return NULL;
	}

	return scene.GetObjectPtr( indexClosest );
}

Vec3 FindAverage( List<Vec3> vecs ) {
	Vec3 sum( 0 );
	for( uint32_t i = 0; i < vecs.Count(); i++ ) {
		sum = sum + vecs[ i ];
	}
	return sum / real_t( vecs.Count() );
}
