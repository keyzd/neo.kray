#ifndef IMATERIAL_H
#define IMATERIAL_H

#include "Light.h"
#include "ShadeRecord.h"

/*
class IRenderer;
typedef IRenderer Renderer;
class IScene;
typedef IScene Scene;
class ICamera;
typedef ICamera Camera;
*/

class IMaterial;
typedef IMaterial Material;

class IMaterial {
public:
	virtual ~IMaterial() {}

//	virtual Vec3 Shade( const ShadeRecord& shadeRec, const Renderer& renderer,
//						const Scene& scene, const Camera& camera ) const = 0;

	virtual Vec3 Shade( const ShadeRecord& shadeRec ) const = 0;

	void SetSurfaceColor( const Vec3& a_color );
	Vec3 GetSurfaceColor() const;

	void SetDiffuseCoefficient( real_t coeff );
	real_t GetDiffuseCoefficient() const;

	void SetSpecularCoefficient( real_t coeff );
	real_t GetSpecularCoefficient() const;

	void SetReflectivenessCoefficient( real_t coeff );
	real_t GetReflectivenessCoefficient() const;

protected:
	Vec3 surfaceColor;
	real_t kD;
	real_t kS;

private:
	real_t kR;
};

inline void IMaterial::SetSurfaceColor( const Vec3& a_color ) {
	surfaceColor = a_color;
}

inline void IMaterial::SetDiffuseCoefficient( real_t coeff ) {
	kD = coeff;
}

inline void IMaterial::SetSpecularCoefficient( real_t coeff ) {
	kS = coeff;
}

inline void IMaterial::SetReflectivenessCoefficient( real_t coeff ) {
	kR = coeff;
}

inline Vec3 IMaterial::GetSurfaceColor() const {
	return surfaceColor;
}

inline real_t IMaterial::GetDiffuseCoefficient() const {
	return kD;
}

inline real_t IMaterial::GetSpecularCoefficient() const {
	return kS;
}

inline real_t IMaterial::GetReflectivenessCoefficient() const {
	return kR;
}


#endif
