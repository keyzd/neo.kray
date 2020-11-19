#include "MaterialGlass.h"

Vec3 MaterialGlass::Shade( const ShadeRecord& shadeRec, const Renderer& renderer, const Scene& scene,
						   const Camera& camera ) const {
	Ray ray;
	ray.SetOrigin( shadeRec.hitPoint );
	ray.SetDirection( (shadeRec.toCamDir * -1).Normalize() );

	renderer.RayTrace( ray, scene, camera );
}
