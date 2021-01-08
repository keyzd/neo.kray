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
	SetBackgroundColor( Vec3(0.3, 0.3, 0.3) );

	Vec3 pos1( -0.3, 0.0, 1.2 ), pos2( 2.8, -0.2, 4.1 );

	ObjectSphere* s1 = new ObjectSphere( pos1, 0.5 );
	s1->material = new MaterialNormalMap();

	ObjectSphere* s2 = new ObjectSphere( pos2, 0.8 );
	s2->material = new MaterialPhong();
	s2->material->reflective = 0.65;
	s2->material->SetSurfaceColor( Vec3( 1.0, 1,  1) );
	s2->material->SetDiffuseCoefficient( 0.8 );
	s2->material->SetSpecularCoefficient( 1.0 );

	ObjectPlane *p1 = new ObjectPlane();
	p1->SetPosition( Vec3 (0, -1,  0) );
	p1->SetNormal( Vec3 (0.0, -1,  0) );
	p1->SetR( Vec3 (1, 0,  0) );
	p1->material = new MaterialPhong;
	p1->material->reflective = 0.07;
	p1->material->SetSurfaceColor( Vec3( 1, 1,  1) );
	p1->material->SetDiffuseCoefficient( -1.0 );
	p1->material->SetSpecularCoefficient( 0.0 );

	Light* l1 = new Light( LightType::point );
	l1->SetIntensity( 0.8 );
	l1->SetSpecularCoefficient( 100 );
	l1->SetLightPosition( Vec3(0.0, 0.0, 0.0) );

	SetLight( l1 );
	SetObject( s1 );
	SetObject( s2 );
	SetObject( p1 );
}
