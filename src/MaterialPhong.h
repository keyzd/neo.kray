#ifndef MATERIAL_PHONG_H
#define MATERIAL_PHONG_H

#include "IMaterial.h"

class MaterialPhong : public IMaterial {
public:
	virtual Vec3 Shade( const ShadeRecord& shadeRec ) const;

private:
	Vec3 Diffuse( const Vec3& normal, const Vec3& lightDir, const Vec3&  camera ) const;
	Vec3 Specular( const Vec3& normal, const Vec3& lightDir, const Vec3&  camera,
				   real_t exp ) const;
};

#endif
