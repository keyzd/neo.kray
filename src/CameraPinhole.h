#ifndef CAMERA_PINHOLE_H
#define CAMERA_PINHOLE_H

#include "ICamera.h"

#include <stdint.h>
#include <math.h>

class CameraPinhole : public ICamera {
public:
	CameraPinhole( uint32_t a_resWidth, uint32_t a_resHeight );
	virtual ~CameraPinhole() {}

	virtual Ray GetRay( uint32_t canvasX, uint32_t canvasY ) const;
	virtual void SetFov( real_t a_fov );
	virtual real_t GetFov() const;
};

inline CameraPinhole::CameraPinhole( uint32_t a_resWidth, uint32_t a_resHeight ) :
	ICamera( a_resWidth, a_resHeight ) {
		SetFov( 60.0 );
}

#endif
