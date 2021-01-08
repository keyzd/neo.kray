#ifndef DEFAULT_RENDERER_H
#define DEFAULT_RENDERER_H

#include "IRenderer.h"
#include "utils/List.h"
#include "utils/Pair.h"

class DefaultRenderer : public IRenderer {
public:
	DefaultRenderer();

	virtual void MakeImage( Canvas& canvas, const Scene& scene, const Camera& camera );
	virtual Vec3 RayTrace( const Ray& ray, const Scene& scene, const Camera& camera, int RecDepth );

protected:
	virtual Object* FindClosestObject( const Ray& ray, const Scene& scene, const Camera& camera,
							   real_t lenMin, real_t lenMax);
	// Phong reflection model
	virtual Vec3 CalculateLight( const Camera& camera, const Scene& scene, const Vec3& normal,
						 		 const Vec3& intersection, Material* objectMaterial );

private:
	uint32_t aaSamplesCount;
	List<Pair<real_t, real_t>> aaParams;
};

#endif
