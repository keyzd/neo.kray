#ifndef SCENE_1_H
#define SCENE_1_H

#include "src/IScene.h"
#include "src/ICamera.h"

class Scene1 : public IScene {
public:
	virtual void Setup( Camera& camera, double time );
};

#endif
