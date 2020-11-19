#include <stdlib.h>

#include "CameraPinhole.h"

Ray CameraPinhole::GetRay( uint32_t canvasX, uint32_t canvasY ) const {
	real_t aspectRatio = real_t( resWidth ) / real_t( resHeight );
	real_t u = real_t( canvasX*2 ) / real_t( resWidth ) - 1.0;
	real_t v = real_t( canvasY*2 ) / real_t( resHeight ) - 1.0;
	u *= aspectRatio;
	Vec3 direction( u, -v, projPlaneDistance );
	return Ray( origin, direction.Normalize() );
}

void CameraPinhole::SetFov( real_t a_fov ) {
	a_fov = a_fov * M_PI / 180.0;
	real_t beta = M_PI_2 - a_fov * 0.5;
	real_t l = real_t( resWidth ) / real_t( resHeight ) * 0.5;
	projPlaneDistance = tanl( beta ) * l * 0.5;
	fov = a_fov;
}

inline real_t CameraPinhole::GetFov() const {
	return fov;
}
