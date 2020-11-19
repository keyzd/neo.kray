#ifndef ICAMERA_H
#define ICAMERA_H

#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#include "utils/List.h"
#include "utils/Pair.h"

#include "Ray.h"

class ICamera;
typedef ICamera Camera;

class ICamera {
public:
	ICamera( const uint32_t a_resWidth, const uint32_t a_resHeight );
	virtual ~ICamera() {}

	virtual Ray GetRay( const uint32_t canvasX, const uint32_t canvasY ) const = 0;
	virtual void SetFov( const real_t a_fov ) = 0;
	virtual real_t GetFov() const = 0;

	void SetOrigin( const Vec3& a_origin );
	Vec3 GetOrigin() const;
	real_t GetProjPlaneDistance() const;

	Vec3 ApplyRotations( const Ray& ray ) const;
	void RotateYX( const real_t aRad );
	void RotateYZ( const real_t aRad );
	void RotateZX( const real_t aRad );

protected:
	uint32_t resWidth;
	uint32_t resHeight;
	Vec3 origin;
	real_t projPlaneDistance;
	real_t fov;

private:
	enum Axis {
		YX, YZ, ZX
	};

	List<Pair<Axis, real_t>> rotationPair;

	void _RotateYX( const real_t aRad, Vec3& dir ) const;
	void _RotateYZ( const real_t aRad, Vec3& dir ) const;
	void _RotateZX( const real_t aRad, Vec3& dir ) const;
};

inline ICamera::ICamera( const uint32_t a_resWidth, const uint32_t a_resHeight ) {
	resWidth = a_resWidth;
	resHeight = a_resHeight;
}

inline void ICamera::SetOrigin( const Vec3& a_origin ) {
	origin = a_origin;
}

inline Vec3 ICamera::GetOrigin() const {
	return origin;
}

inline real_t ICamera::GetProjPlaneDistance() const {
	return projPlaneDistance;
}

#endif
