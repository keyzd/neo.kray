#include "src/Light.h"
#include "src/IObject.h"
#include "src/ObjectSphere.h"
#include "src/ObjectCylinder.h"
#include "src/ObjectPlane.h"
#include "src/MaterialPhong.h"
#include "src/MaterialNormalMap.h"
#include "src/IScene.h"

#include "Scene3.h"

#include <stdio.h>
#include <math.h>

void Scene3::Setup( Camera& camera, double time ) {
	SetBackgroundColor( Vec3( 0.7, 0.7, 0.8 ) );
	camera.SetFov( 40 );

	real_t tsin = sin( time );
	real_t tcos = cos( time );

	ObjectSphere* s1 = new ObjectSphere( Vec3( 0.5, 0.0, 3.0 ), 0.5 );
	s1->material = new MaterialNormalMap;

	ObjectSphere* s2 = new ObjectSphere( Vec3(0.0, 0.0, 100.0), 50.0 );
	s2->material = new MaterialPhong;
	s2->material->SetSurfaceColor( Vec3( 1.0, 0.8, 1.0 ) );
	s2->material->SetDiffuseCoefficient( 1.0 );
	s2->material->SetSpecularCoefficient( 0 );

	Light* l1 = new Light( LightType::point );
	l1->SetIntensity( 0.8 );
	l1->SetSpecularCoefficient( 100 );
	l1->SetLightPosition( Vec3( tsin, tcos, tsin*tcos ) );

	Light* l2 = new Light( LightType::ambient );
	l2->SetIntensity( 0.2 );

	SetObject( s1 );
	SetObject( s2 );
	SetLight( l1 );
	SetLight( l2 );
}
