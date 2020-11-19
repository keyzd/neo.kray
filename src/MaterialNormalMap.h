#ifndef MATERIAL_NORMAL_MAP
#define MATERIAL_NORMAL_MAP

#include "IMaterial.h"

class MaterialNormalMap : public IMaterial {
public:
	virtual Vec3 Shade( const ShadeRecord& shadeRec ) const;
};

#endif
