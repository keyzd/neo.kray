#ifndef LIGHT_H
#define LIGHT_H

#include "Vec3.h"

enum LightType {
	ambient, point, directional
};

class Light {
public:
	Light( LightType atype ) { type = atype; }

	LightType GetType() const;

	void SetIntensity( real_t a_intensity );
	real_t GetIntensity() const;

	void SetLightPosition( const Vec3 &a_position );
	Vec3 GetLightPosition() const;

	void SetLightDirection( const Vec3 &a_direction );
	Vec3 GetLightDirection() const;

	void SetSpecularCoefficient( real_t a_coeff );
	real_t GetSpecularCoefficient() const;

private:
	LightType type;
	real_t intensity;
	Vec3 position, direction;
	real_t specularCoefficient;
};

inline LightType Light::GetType() const {
	return type;
}

inline void Light::SetIntensity( real_t a_intensity ) {
	if( a_intensity > 1.0 ) {
		a_intensity = 1.0;
	}
	else if( a_intensity < 0.0 ) {
		a_intensity = 0.0;
	}
	intensity = a_intensity;
}

inline real_t Light::GetIntensity() const {
	return intensity;
}

inline void Light::SetLightPosition( const Vec3 &a_position ) {
	position = a_position;
}

inline Vec3 Light::GetLightPosition() const {
	return position;
}

inline void Light::SetLightDirection( const Vec3 &a_direction ) {
	direction = a_direction;
}

inline Vec3 Light::GetLightDirection() const {
	return direction;
}

inline void Light::SetSpecularCoefficient( real_t a_coeff ) {
	specularCoefficient = a_coeff;
}

inline real_t Light::GetSpecularCoefficient() const {
	return specularCoefficient;
}

#endif
