#ifndef ISCENE_H
#define ISCENE_H

#include <stdint.h>

#include "utils/List.h"
#include "ICamera.h"
#include "IObject.h"

class IScene;
typedef IScene Scene;

class IScene {
public:
	virtual void Setup( Camera& camera, double time ) = 0;

	void SetBackgroundColor( const Vec3 &a_bgcolor );
	Vec3 GetBackgroundColor() const;

	void SetObject( Object *object );
	void SetLight( Light *light );

	uint32_t CountObjects() const;
	Object* GetObjectPtr( uint32_t i ) const;

	uint32_t CountLight() const;
	Light* GetLightPtr( uint32_t i ) const;

	virtual ~IScene() {
		for(uint32_t i = 0; i < listObjects.Count(); i++ ) {
			listObjects[ i ]->Delete();
		}

		for(uint32_t i = 0; i < listLights.Count(); i++ ) {
			delete listLights[ i ];
		}
	}

private:
	List<Object*> listObjects;
	List<Light*> listLights;
	Vec3 bg_color;

};

inline void IScene::SetBackgroundColor( const Vec3 &a_bgcolor ) {
	bg_color = a_bgcolor;
}

inline Vec3 IScene::GetBackgroundColor() const {
	return bg_color;
}

inline void IScene::SetObject( Object *object ) {
	listObjects.Push( object );
}

inline void IScene::SetLight( Light *light ) {
	listLights.Push( light );
}

inline uint32_t IScene::CountObjects() const {
	return listObjects.Count();
}

inline Object* IScene::GetObjectPtr( uint32_t i ) const {
	return listObjects[ i ];
}

inline uint32_t IScene::CountLight() const {
	return listLights.Count();
}

inline Light* IScene::GetLightPtr( uint32_t i ) const {
	return listLights[ i ];
}

#endif
