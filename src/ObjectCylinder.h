#ifndef OBJECT_CYLINDER_H
#define OBJECT_CYLINDER_H

#include "IObject.h"

class ObjectCylinder : public IObject {
public:
	ObjectCylinder();
	ObjectCylinder( const Vec3& pos, const real_t a_radius, const real_t a_height );

	void SetRadius( const real_t rad );
	real_t GetRadius() const;

	void SetHeight( const real_t a_height );
	real_t GetHeight() const;

	virtual bool Intersect( const Ray &ray, Vec3 &intersect_at ) const;
	virtual Vec3 NormalAt( const Vec3 &intersect_at ) const;

private:
	virtual ~ObjectCylinder() {}

	real_t radius;
	real_t height;
};

inline ObjectCylinder::ObjectCylinder() {
}

inline ObjectCylinder::ObjectCylinder( const Vec3& pos, const real_t rad, const real_t a_height ) :
	IObject( pos ), radius( rad ), height( a_height ) {
}

inline void ObjectCylinder::SetRadius( const real_t rad ) {
	radius = rad;
}

inline real_t ObjectCylinder::GetRadius() const {
	return radius;
}

inline void ObjectCylinder::SetHeight( const real_t a_height ) {
	height = a_height;
}

inline real_t ObjectCylinder::GetHeight() const {
	return height;
}

#endif
