#ifndef IRENDERER_H
#define IRENDERER_H

#include "IScene.h"
#include "Canvas.h"

class IRenderer;
typedef IRenderer Renderer;

class IRenderer {
public:
	virtual ~IRenderer() {}
	virtual void MakeImage( Canvas& canvas, const Scene& scene, const Camera& camera ) = 0;
	virtual Vec3 RayTrace( const Ray& ray, const Scene& scene, const Camera& camera ) = 0;

protected:
	virtual Object* FindClosestObject( const Ray& ray, const Scene& scene, const Camera& camera,
							   real_t lenMin, real_t lenMax) = 0;
	virtual Vec3 CalculateLight( const Camera& camera, const Scene& scene, const Vec3& normal,
						 		 const Vec3& intersection, Material* objectMaterial ) = 0;

};

#endif
