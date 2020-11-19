#ifndef SCENE_3_H
#define SCENE_3_H

#include "src/IScene.h"
#include "src/ICamera.h"

class Scene3 : public IScene {
public:
	virtual void Setup( Camera& camera, double time );
};

#endif
