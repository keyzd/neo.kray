#include "src/Light.h"
#include "src/IObject.h"
#include "src/ObjectSphere.h"
#include "src/ObjectCylinder.h"
#include "src/ObjectPlane.h"
#include "src/MaterialPhong.h"
#include "src/MaterialNormalMap.h"
#include "src/IScene.h"

#include "Scene5.h"

#include <stdio.h>
#include <math.h>

void Scene5::Setup( Camera& camera, double time ) {
	SetBackgroundColor( Vec3(0.8, 0.8, 1.0) );

	Light* l1 = new Light( LightType::point );
	l1->SetIntensity(1.0);
	l1->SetLightPosition( Vec3(0, -1, 1) );
	SetLight(l1);

	ObjectSphere* s1 = new ObjectSphere( Vec3(-1, 0, 2), 1.0 );
	s1->material = new MaterialPhong;
	s1->material->SetSurfaceColor( Vec3( 1.0, 0, 0) );
	s1->material->SetDiffuseCoefficient( 1.0 );
	SetObject(s1);

	ObjectCylinder* c1 = new ObjectCylinder( Vec3(0.6, 0.0, 5.4), 3.0, 2.0);
	c1->material = new MaterialPhong;
	c1->material->SetSurfaceColor( Vec3( 1.0, 0, 0.6) );
	c1->material->SetDiffuseCoefficient( 1.0 );
	SetObject(c1);

	ObjectPlane *p1 = new ObjectPlane();
	p1->SetPosition( Vec3 (0, -5,  0) );
	p1->SetNormal( Vec3 (0.0, -1,  0) );
	p1->SetR( Vec3 (1, 0,  0) );
	p1->material = new MaterialPhong;
	p1->material->SetSurfaceColor( Vec3(1, 1,  1) );
	p1->material->SetDiffuseCoefficient( -1.0 );
	SetObject(p1);
}
