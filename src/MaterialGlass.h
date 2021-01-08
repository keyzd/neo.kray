#ifndef MATERIAL_GLASS_H
#define MATERIAL_GLASS_H

#include "IMaterial.h"
#include "Light.h"

class MaterialGlass : public IMaterial {
public:
//	virtual Vec3 Shade( const ShadeRecord& shadeRec, const Renderer& renderer, const Scene& scene,
//						const Camera& camera ) const;

	virtual Vec3 Shade( const ShadeRecord& shadeRec ) const = 0;
};

#endif
