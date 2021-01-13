#include "MaterialPhongCheckmate.h"

Vec3 MaterialPhongCheckmate::Shade( const ShadeRecord& shadeRec) const {

	real_t x = shadeRec.hitPoint.x;
	real_t y = shadeRec.hitPoint.y;
	real_t z = shadeRec.hitPoint.z;

	if( ( (int)floor(x/cellSize)+(int)floor(y/cellSize)+(int)floor(z/cellSize) ) % 2 == 0 ) 
		return Diffuse( shadeRec.normal, shadeRec.toLightDir, shadeRec.toCamDir, color1 ) * shadeRec.light->GetIntensity() +
			   Specular( shadeRec.normal, shadeRec.toLightDir, shadeRec.toCamDir, shadeRec.light->GetSpecularCoefficient() );

	return Diffuse( shadeRec.normal, shadeRec.toLightDir, shadeRec.toCamDir, color2 ) * shadeRec.light->GetIntensity() +
		   Specular( shadeRec.normal, shadeRec.toLightDir, shadeRec.toCamDir, shadeRec.light->GetSpecularCoefficient() );

//	return Diffuse( shadeRec.normal, shadeRec.toLightDir, shadeRec.toCamDir ) * shadeRec.light->GetIntensity() +
//		   Specular( shadeRec.normal, shadeRec.toLightDir, shadeRec.toCamDir, shadeRec.light->GetSpecularCoefficient() );
}

Vec3 MaterialPhongCheckmate::Diffuse( const Vec3& normal, const Vec3& lightDir, const Vec3&  camDir, Vec3 color ) const {
	return color * kD * normal.Dot( lightDir.Normalize() );
}

Vec3 MaterialPhongCheckmate::Specular( const Vec3& normal, const Vec3& lightDir, const Vec3&  camDir,
					  const real_t exp ) const {
	Vec3 color( 0 );
	Vec3 r = lightDir.Reflect( normal ).Normalize();
	real_t rDotD = r.Dot( camDir.Normalize() );

	if( rDotD > 0.0 ) {
		color = powl( rDotD,  exp) * kS;
	}

	return color;
}


