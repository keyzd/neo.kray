#ifndef OBJECT_PLANE_H
#define OBJECT_PLANE_H

#include "IObject.h"

class ObjectPlane : public IObject {
public:
	ObjectPlane();
	ObjectPlane( const Vec3& a_pos, const Vec3& a_normal, const Vec3& a_r );

	void SetNormal( const Vec3& a_normal );
	void SetR( const Vec3& a_r );

	virtual bool Intersect( const Ray &ray, Vec3 &intersect_at ) const;
	virtual Vec3 NormalAt( const Vec3 &intersect_at ) const;

private:
	virtual ~ObjectPlane() {}

	Vec3 r;
	Vec3 normal;
};

inline ObjectPlane::ObjectPlane() {
}

inline ObjectPlane::ObjectPlane( const Vec3& a_pos, const Vec3& a_normal, const Vec3& a_r ) {
	position = a_pos;
	normal = a_normal;
	r = a_r;
}

inline void ObjectPlane::SetNormal( const Vec3& a_normal ) {
	normal = a_normal.Normalize();
}

inline void ObjectPlane::SetR( const Vec3& a_r ) {
}

#endif
