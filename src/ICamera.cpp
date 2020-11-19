#include <stdio.h>
#include "ICamera.h"

void ICamera::RotateYX( const real_t a ) {
	Pair<Axis, real_t> pair;
	pair.SetPair( Axis::YX, a );
	rotationPair.Push( pair );
}

void ICamera::RotateYZ( const real_t a ) {
	Pair<Axis, real_t> pair;
	pair.SetPair( Axis::YZ, a );
	rotationPair.Push( pair );
}

void ICamera::RotateZX( const real_t a ) {
	Pair<Axis, real_t> pair;
	pair.SetPair( Axis::ZX, a );
	rotationPair.Push( pair );
}

void ICamera::_RotateYX( const real_t aRad, Vec3& dir ) const {
	Vec3 newDir;

	newDir.x = dir.x*cos( aRad ) + dir.y*sin( aRad );
	newDir.y = -dir.x*sin( aRad ) + dir.y*cos( aRad );
	newDir.z = dir.z;
	dir = newDir;
}

void ICamera::_RotateYZ( const real_t aRad, Vec3& dir ) const {
	Vec3 newDir;

	newDir.z = dir.z*cos( aRad ) + dir.y*sin( aRad );
	newDir.y = -dir.z*sin( aRad ) + dir.y*cos( aRad );
	newDir.x = dir.x;
	dir = newDir;
}

void ICamera::_RotateZX( const real_t aRad, Vec3& dir ) const {
	Vec3 newDir;

	newDir.x = dir.x*cos( aRad ) + dir.z*sin( aRad );
	newDir.z = -dir.x*sin( aRad ) + dir.z*cos( aRad );
	newDir.y = dir.y;
	dir = newDir;
}

Vec3 ICamera::ApplyRotations( const Ray& ray ) const {
	Vec3 dir = ray.GetDirection();

	for( uint32_t i = 0; i < rotationPair.Count(); i++ ) {
		Axis axis = rotationPair[ i ].el1;
		real_t a = rotationPair[ i ].el2;

		if( axis == Axis::YX ) {
			_RotateYX( a, dir );
		} else if( axis == Axis::YZ ) {
			_RotateYZ( a, dir );
		} else {
			_RotateZX( a, dir );
		}
	}

	return dir;
}
