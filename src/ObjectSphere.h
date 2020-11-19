#ifndef OBJECT_SPHERE_H
#define OBJECT_SPHERE_H

#include "IObject.h"

class ObjectSphere : public IObject {
public:
	ObjectSphere();
	ObjectSphere( const Vec3 &pos, const real_t rad );

	real_t GetRadius() const;
	void SetRadius( const real_t rad );

	virtual bool Intersect( const Ray &ray, Vec3 &intersect_at ) const;
	virtual Vec3 NormalAt( const Vec3 &intersect_at ) const;

private:
	virtual ~ObjectSphere() {}

	real_t radius;
};

inline ObjectSphere::ObjectSphere() {
}

inline ObjectSphere::ObjectSphere( const Vec3 &pos, const real_t rad ) :
	IObject( pos ), radius( rad ) {
}

real_t inline ObjectSphere::GetRadius() const {
	return radius;
}

void inline ObjectSphere::SetRadius( const real_t rad ) {
	radius = rad;
}

#endif
