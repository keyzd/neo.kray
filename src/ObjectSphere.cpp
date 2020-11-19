#include "ObjectSphere.h"

/*
bool ObjectSphere::Intersect( const Ray &ray, Vec3 &intersect_at ) const {
	Vec3 dir = ray.GetDirection() - ray.GetOrigin();

	if( dir.Dot( this->GetPosition() ) <= 0.00 ) {
		return false;
	}

	Vec3 dirn = dir.Normalize();
	Vec3 op = dirn * ( this->GetPosition().Dot(dirn) );
	Vec3 cp = op - this->GetPosition();

	if( cp.Length() <= this->GetRadius() ) {
		real_t pn = sqrtf( powf( this->GetRadius(), 2. ) - powf( cp.Length(), 2. ) );
		intersect_at = op-pn;
		return true;
	} else {
		return false;
	}
}
*/

bool ObjectSphere::Intersect( const Ray &ray, Vec3 &intersect_at ) const {

	Vec3 oc = ray.GetOrigin() - position;
	real_t a = ray.GetDirection().Dot( ray.GetDirection() );
	real_t b = oc.Dot( ray.GetDirection() ) * 2.0;
	real_t c = oc.Dot( oc ) - radius*radius;
	real_t discr = b * b - 4 * a * c;

	if(discr < 0.0) {
		return false;
	}

	real_t t1 = ( -b + sqrt( discr ) ) / ( 2.0 * a );
	real_t t2 = ( -b - sqrt( discr ) ) / ( 2.0 * a );
	real_t t;
	if( t1 < t2) {
		t = t1;
	} else {
		t = t2;
	}

	intersect_at = ray.GetOrigin() + ray.GetDirection() * t;

	return true;
}

Vec3 ObjectSphere::NormalAt( const Vec3 &intersect_at ) const {
	return ( intersect_at - this->GetPosition() ).Normalize();
}
