#include "src/Light.h"
#include "src/IObject.h"
#include "src/ObjectSphere.h"
#include "src/ObjectCylinder.h"
#include "src/ObjectPlane.h"
#include "src/MaterialPhong.h"
#include "src/MaterialNormalMap.h"
#include "src/IScene.h"

#include "Scene2.h"

#include <stdio.h>
#include <math.h>

void Scene2::Setup( Camera& camera, double time ) {
	SetBackgroundColor( Vec3( 0.7, 0.7, 0.8 ) );

	real_t t = sin( time ) / 20.;
	real_t a = 10.*3.14159265/180.0;
	camera.RotateYZ( a*t );

	Light* l1 = new Light( LightType::point );
	l1->SetIntensity( 1.0 );
	l1->SetSpecularCoefficient( 100 );
	l1->SetLightPosition( Vec3( 0.0, 0.0, 0.0 ) );

	ObjectSphere* s1 = new ObjectSphere( Vec3( 0.0, 0.0, 5.0 ), 1 );
	s1->material = new MaterialNormalMap;

	SetObject( s1 );
	SetLight( l1 );
}
