#include "src/Light.h"
#include "src/IObject.h"
#include "src/ObjectSphere.h"
#include "src/ObjectCylinder.h"
#include "src/ObjectPlane.h"
#include "src/MaterialPhong.h"
#include "src/MaterialNormalMap.h"
#include "src/IScene.h"

#include "Scene4.h"

#include <stdio.h>
#include <math.h>

void Scene4::Setup( Camera& camera, double time ) {
	ObjectSphere* s1 = new ObjectSphere( Vec3(0.0, 0.0, 3.0), 0.5 );
	s1->material = new MaterialNormalMap();

	Light* l1 = new Light( LightType::point );
	l1->SetIntensity( 0.8 );
	l1->SetSpecularCoefficient( 100 );
	l1->SetLightPosition( Vec3(0.0, 0.0, 0.0) );

	SetLight( l1 );
	SetObject( s1 );
}
