#ifndef SCENE_5_H
#define SCENE_5_H

#include "src/IScene.h"
#include "src/ICamera.h"

class Scene5 : public IScene {
public:
	virtual void Setup( Camera& camera, double time );
};

#endif
