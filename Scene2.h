#ifndef SCENE_2_H
#define SCENE_2_H

#include "src/IScene.h"
#include "src/ICamera.h"

class Scene2 : public IScene {
public:
	virtual void Setup( Camera& camera, double time );
};

#endif
