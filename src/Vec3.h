#ifndef VEC3_H
#define VEC3_H

#include <math.h>

typedef double real_t;

class Vec3 {
public:
	union {
		struct { real_t x, y, z; };
		struct { real_t r, g, b; };
	};

	Vec3(real_t a_x, real_t a_y, real_t a_z);
	Vec3(real_t a);
	Vec3();

	real_t Length() const;
	real_t Dot(const Vec3 &v) const;
	Vec3 Normalize() const;
	Vec3 Reflect(Vec3 n) const;

	const Vec3& operator+() const;
	const Vec3 operator-() const;
	Vec3 operator+(const Vec3 &v) const;
	Vec3 operator-(const Vec3 &v) const;
	Vec3 operator+(const real_t t) const;
	Vec3 operator-(const real_t t) const;
	const Vec3& operator=(const Vec3 &v);
	const Vec3& operator*=(const real_t t);
	const Vec3& operator/=(const real_t t);
	const Vec3& operator+=(const Vec3& v);
	const Vec3& operator-=(const Vec3& v);
	Vec3 operator*(const real_t t) const;
	Vec3 operator/(const real_t t) const;
	bool operator==( const Vec3& u ) const;

};

//==================================================
inline Vec3 operator*(const real_t t, const Vec3 &u) {
	return Vec3(u.x*t, u.y*t, u.z*t);
}

inline Vec3 operator/(const real_t t, const Vec3 &u) {
	return Vec3(u.x/t, u.y/t, u.z/t);
}

inline Vec3 operator+(const real_t t, const Vec3 &u) {
	return Vec3(u.x+t, u.y+t, u.z+t);
}

inline Vec3 operator-(const real_t t, const Vec3 &u) {
	return Vec3(u.x-t, u.y-t, u.z-t);
}
//==================================================

inline Vec3::Vec3(real_t a_x, real_t a_y, real_t a_z) {
	x = a_x; y = a_y; z = a_z;
}

inline Vec3::Vec3(real_t a) {
	x = y = z = a;
}

inline Vec3::Vec3() {
	x = y = z = 0;
}

inline const Vec3& Vec3::operator+() const {
	return *this;
}

inline const Vec3 Vec3::operator-() const {
	return Vec3(-x, -y, -z);
}

inline Vec3 Vec3::operator+(const Vec3 &v) const {
	return Vec3(x+v.x, y+v.y, z+v.z);
}

inline Vec3 Vec3::operator-(const Vec3 &v) const {
	return Vec3(x-v.x, y-v.y, z-v.z);
}

inline Vec3 Vec3::operator+(const real_t t) const {
	return Vec3(x+t, y+t, z+t);
}

inline Vec3 Vec3::operator-(const real_t t) const {
	return Vec3(x-t, y-t, z-t);
}

inline const Vec3& Vec3::operator=(const Vec3 &v) {
	x = v.x; y = v.y; z = v.z;
	return *this;
}

inline const Vec3& Vec3::operator*=(const real_t t) {
	x *= t; y *= t; z *= t;
	return *this;
}

inline const Vec3& Vec3::operator/=(const real_t t) {
	x /= t; y /= t; z /= t;
	return *this;
}

inline const Vec3& Vec3::operator+=(const Vec3& v) {
	x += v.x; y += v.y; z += v.z;
	return *this;
}

inline const Vec3& Vec3::operator-=(const Vec3& v) {
	x -= v.x; y -= v.y; z -= v.z;
	return *this;
}

inline Vec3 Vec3::operator*(const real_t t) const {
	return Vec3(this->x*t, this->y*t, this->z*t);
}

inline Vec3 Vec3::operator/(const real_t t) const {
	return Vec3(this->x/t, this->y/t, this->z/t);
}

inline real_t Vec3::Length() const {
	return sqrtf(x*x+y*y+z*z);
}

inline real_t Vec3::Dot(const Vec3 &v) const {
	return this->x*v.x + this->y*v.y + this->z*v.z;
}

inline Vec3 Vec3::Normalize() const {
	real_t length = this->Length();
	return Vec3(x/length, y/length, z/length);
}

inline Vec3 Vec3::Reflect(Vec3 n) const {
//	return *this - n*2*this->Dot(n);
	return n*2*this->Dot(n) - *this;
}

inline bool Vec3::operator==( const Vec3& u ) const {
	if( x == u.x && y == u.y && z == u.z ) {
		return true;
	}
	return false;
}

#endif
