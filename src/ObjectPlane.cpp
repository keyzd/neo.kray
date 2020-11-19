#include "ObjectPlane.h"

bool ObjectPlane::Intersect( const Ray &ray, Vec3 &intersect_at ) const {
	Vec3 dir = ( ray.GetDirection() - ray.GetOrigin() );

	if( normal.Dot( dir.Normalize() ) <= 0.0 ) {
		return false;
	}

	real_t a = normal.x;
	real_t b = normal.y;
	real_t c = normal.z;

	Vec3 tmp = ( position - r ) - ray.GetOrigin();
	Vec3 d = ray.GetDirection();
	real_t t = ( a*tmp.x + b*tmp.y + c*tmp.z ) / ( a*d.x + b*d.y + c*d.z );

	intersect_at = dir*t;

	return true;
}

Vec3 ObjectPlane::NormalAt( const Vec3 &intersect_at ) const {
	return normal;
}

