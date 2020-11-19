#include "ObjectCylinder.h"

bool ObjectCylinder::Intersect( const Ray& ray, Vec3& intersect_at ) const {
	Vec3 dir = ray.GetDirection() - ray.GetOrigin();
	Vec3 o = ray.GetOrigin();

	if( dir.Dot( this->GetPosition() ) <= 0.00 ) {
		return false;
	}

	Vec3 dirn = dir.Normalize();

	real_t dz = dirn.z;
	real_t oz = o.z;
	real_t pz = GetPosition().z;

	real_t px = GetPosition().x;
	real_t py = GetPosition().y;

	real_t a = dirn.x*dirn.x + dz*dz;
	real_t b = 2. * ( o.x*dirn.x + oz*dz - dirn.x*px - dz*pz );
	real_t c = o.x*o.x + px*px - 2.*o.x*px + oz*oz + pz*pz - 2.*oz*pz - radius*radius;

	real_t discr = b*b - 4.*a*c;

	if( discr < 0.0 ) {
		return false;
	}

	real_t t1 =  ( -b + sqrtl( discr ) ) / ( 2. * a );
	real_t t2 =  ( -b - sqrtl( discr ) ) / ( 2. * a );
	real_t t = t1 > t2 ? t2 : t1;

	Vec3 intersection = o + dir * t;
	if( ( intersection.y > py + height ) || ( intersection.y < py - height ) )
		return false;

	intersect_at = o + dir * t; 

	return true;
}

Vec3 ObjectCylinder::NormalAt( const Vec3 &intersect_at ) const {
//	return Vec3( intersect_at.x/radius, 0, intersect_at.z/radius ).Normalize()*-1.;
//
	real_t l = GetPosition().y - intersect_at.y;
	Vec3 p = GetPosition();

	if( l < 0.0 ) {
		p.y += fabsl( l );
	} else {
		p.y -= fabsl( l );
	}

	Vec3 normal = intersect_at - p;
	normal.y = 0;
	return normal.Normalize();
}
