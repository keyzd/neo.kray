#include "MaterialPhong.h"

Vec3 MaterialPhong::Shade( const ShadeRecord& shadeRec) const {

	return Diffuse( shadeRec.normal, shadeRec.toLightDir, shadeRec.toCamDir ) * shadeRec.light->GetIntensity() +
		   Specular( shadeRec.normal, shadeRec.toLightDir, shadeRec.toCamDir, shadeRec.light->GetSpecularCoefficient() );
}

Vec3 MaterialPhong::Diffuse( const Vec3& normal, const Vec3& lightDir, const Vec3&  camDir ) const {
	return surfaceColor * kD * normal.Dot( lightDir.Normalize() );
}

Vec3 MaterialPhong::Specular( const Vec3& normal, const Vec3& lightDir, const Vec3&  camDir,
					  const real_t exp ) const {
	Vec3 color( 0 );
	Vec3 r = lightDir.Reflect( normal ).Normalize();
	real_t rDotD = r.Dot( camDir.Normalize() );

	if( rDotD > 0.0 ) {
		color = powl( rDotD,  exp) * kS;
	}

	return color;
}
