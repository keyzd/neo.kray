#include "MaterialNormalMap2.h"

Vec3 MaterialNormalMap2::Shade( const ShadeRecord& shadeRec ) const {

	return Vec3( shadeRec.normal.x, shadeRec.normal.y, shadeRec.normal.z ).Normalize();
}
