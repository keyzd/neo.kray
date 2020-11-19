#ifndef IOBJECT_H
#define IOBJECT_H

#include "IMaterial.h"
#include "Ray.h"

class IObject;
typedef IObject Object;

class IObject {
public:
	IObject();
	IObject( const Vec3 &pos );
	void Delete();
	
	void SetPosition( const Vec3 &pos );
	Vec3 GetPosition() const;

	real_t GetX() const;
	real_t GetY() const;
	real_t GetZ() const;

	Material *material;

public:
	virtual bool Intersect( const Ray &ray, Vec3 &intersect_at ) const = 0;
	virtual Vec3 NormalAt( const Vec3 &intersect_at ) const = 0;

protected:
	virtual ~IObject() {}

	Vec3 position;

private:
};

inline void IObject::Delete() {
	delete material;
	delete this;
}

inline IObject::IObject() {
}

inline IObject::IObject( const Vec3 &pos ) {
	position = pos;
}

inline void IObject::SetPosition( const Vec3 &pos ) {
	position = pos;
}

inline Vec3 IObject::GetPosition() const {
	return position;
}

inline real_t IObject::GetX() const {
	return position.x;
}

inline real_t IObject::GetY() const {
	return position.y;
}

inline real_t IObject::GetZ() const {
	return position.z;
}

#endif

