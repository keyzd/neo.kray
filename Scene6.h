#ifndef SCENE_4_H
#define SCENE_4_H

#include "src/IScene.h"
#include "src/ICamera.h"

class Scene4 : public IScene {
public:
	virtual void Setup( Camera& camera, double time );
};

#endif
