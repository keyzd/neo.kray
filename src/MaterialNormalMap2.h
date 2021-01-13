#ifndef MATERIAL_NORMAL_MAP_2
#define MATERIAL_NORMAL_MAP_2

#include "IMaterial.h"

class MaterialNormalMap2 : public IMaterial {
public:
	virtual Vec3 Shade( const ShadeRecord& shadeRec ) const;
};

#endif
