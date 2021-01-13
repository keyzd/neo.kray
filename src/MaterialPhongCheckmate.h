#ifndef MATERIAL_PHONG_CHECKMATE_H
#define MATERIAL_PHONG_CHECKMATE_H

#include "IMaterial.h"

class MaterialPhongCheckmate : public IMaterial {
public:
	virtual Vec3 Shade( const ShadeRecord& shadeRec ) const;

private:
	Vec3 Diffuse( const Vec3& normal, const Vec3& lightDir, const Vec3&  camera, Vec3 color ) const;
	Vec3 Specular( const Vec3& normal, const Vec3& lightDir, const Vec3&  camera,
				   real_t exp ) const;

};

#endif
