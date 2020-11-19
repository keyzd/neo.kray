#include "src/Light.h"
#include "src/IObject.h"
#include "src/ObjectSphere.h"
#include "src/ObjectCylinder.h"
#include "src/ObjectPlane.h"
#include "src/MaterialPhong.h"
#include "src/MaterialNormalMap.h"
#include "src/IScene.h"

#include "Scene1.h"

#include <stdio.h>
#include <math.h>

void setup_box( Scene& scene, double time );
void setup_objs( Scene& scene, double time );
void setup_light( Scene& scene, double time );

real_t x = 0.0;
real_t y = -5.0;
real_t z = 15.0;

void Scene1::Setup( Camera& camera, double time ) {
	real_t d = camera.GetProjPlaneDistance();
	camera.SetOrigin( Vec3( 0, 0, -d ) );
	camera.SetFov( 30 );

	setup_box( *this, time );
	setup_objs( *this, time );
	setup_light( *this, time );
}

void setup_box( Scene& scene, double time ) {
	ObjectSphere *s5 = new ObjectSphere( Vec3( 0, 0, 7030 ), 4000 );
	s5->material = new MaterialPhong;
	s5->material->SetSurfaceColor( Vec3( 0.6, 0.6, 0.6 ) );
	s5->material->SetDiffuseCoefficient( 1.0 );
	s5->material->SetSpecularCoefficient( 0.0 );

	scene.SetObject( s5 );
}

void setup_objs( Scene& scene, double time ) {
	real_t tasin = fabsl( sinl( time ) );
	real_t tacos = fabsl( cosl( time ) );
	real_t tsin = sinl( time );
	real_t tcos = cosl( time );

	ObjectSphere *s1 = new ObjectSphere( Vec3( x, 2, 20 ), tasin+0.3 );
	s1->material = new MaterialPhong;
	s1->material->SetSurfaceColor( Vec3( 0.0, 0.6, 0.6 ) );
	s1->material->SetDiffuseCoefficient( 1.0 );
	s1->material->SetSpecularCoefficient( 1.0 );

	ObjectCylinder *c1 = new ObjectCylinder( Vec3(sinl( time ), 0, 15), 1.5, tacos*3.0+0.5 );
	c1->material = new MaterialPhong;
	c1->material->SetSurfaceColor( Vec3( 0.0, 0.6, 0.0 ) );
	c1->material->SetDiffuseCoefficient( 1.0 );
	c1->material->SetSpecularCoefficient( 1.0 );

	ObjectPlane *p1 = new ObjectPlane();
	p1->SetPosition( Vec3 (0, 50,  0) );
	p1->SetNormal( Vec3 (0.3, 1,  0) );
	p1->SetR( Vec3 (1, 0,  0) );
	p1->material = new MaterialPhong;
	p1->material->SetSurfaceColor( Vec3( 1, 1,  1) );
	p1->material->SetDiffuseCoefficient( -3.0 );
	p1->material->SetSpecularCoefficient( 0.0 );

	ObjectSphere *s2 = new ObjectSphere( Vec3( tsin+1, tcos-2.5, 12 ), 1 );
	s2->material = new MaterialNormalMap;

	scene.SetObject( s1 );
	scene.SetObject( c1 );
	scene.SetObject( p1 );
	scene.SetObject( s2 );
}

void setup_light( Scene& scene, double time ) {
	real_t tasin = fabsl( sinl( time ) );
	real_t tacos = fabsl( cosl( time ) );
	real_t tsin = sinl( time );
	real_t tcos = cosl( time );

	Light* lightAmb = new Light( LightType::ambient );
	lightAmb->SetIntensity( 0.05 );

	Light* lightPoint = new Light( LightType::point );
	lightPoint->SetIntensity( tasin );
	lightPoint->SetLightPosition( Vec3( -7.0, 0.0, 0.0 ) );
	lightPoint->SetSpecularCoefficient( 100 );

	Light* lightPoint2 = new Light( LightType::point );
	lightPoint2->SetIntensity( 0.95 );
	lightPoint2->SetLightPosition( Vec3( x, 0, z ) );
	lightPoint2->SetSpecularCoefficient( 20.0 );

	Light* lightDir = new Light( LightType::directional );
	lightDir->SetIntensity( 0.9 );
	lightDir->SetLightDirection( Vec3( 0, 0, 1 ) );
	lightDir->SetSpecularCoefficient( 10.0 );
	
	scene.SetLight( lightAmb );
	scene.SetLight( lightPoint );
//	scene.SetLight( lightDir );
	scene.SetLight( lightPoint2 );
}
