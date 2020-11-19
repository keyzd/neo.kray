#ifndef RAY_H
#define RAY_H

#include "Vec3.h"

class Ray {
public:
	Ray();
	Ray( const Vec3& origin, const Vec3& direction );

	Vec3 AtPoint( float t ) const;

	void SetOrigin( Vec3 o );
	Vec3 GetOrigin() const;

	void SetDirection( Vec3 d );
	Vec3 GetDirection() const;

private:
	Vec3 O, D;
};

inline Ray::Ray( const Vec3& origin, const Vec3& direction ) {
	O = origin; D = direction;
}

inline Vec3 Ray::AtPoint( float t ) const {
	return O + t*D;
}

inline void Ray::SetOrigin( Vec3 o ) {
	O = o;
}

inline Vec3 Ray::GetOrigin() const {
	return O;
}

inline void Ray::SetDirection( Vec3 d ) {
	D = d;
}

inline Vec3 Ray::GetDirection() const {
	return D;
}

#endif
