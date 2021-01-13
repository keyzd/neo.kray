#include "MaterialNormalMap.h"

Vec3 MaterialNormalMap::Shade( const ShadeRecord& shadeRec ) const {

	return Vec3( shadeRec.normal.x, shadeRec.normal.y, shadeRec.normal.z*-1. ).Normalize();
}
