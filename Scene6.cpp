#include "src/Light.h"
#include "src/IObject.h"
#include "src/ObjectSphere.h"
#include "src/ObjectCylinder.h"
#include "src/ObjectPlane.h"
#include "src/MaterialPhong.h"
#include "src/MaterialNormalMap.h"
#include "src/MaterialPhongCheckmate.h"
#include "src/IScene.h"

#include "Scene4.h"

#include <stdio.h>
#include <math.h>

#define PI 3.14159265
#define DEG2RAD( a ) ( a*PI/180.0 )
#define RAD2DEG( a ) ( a*180.0/PI )

void Scene4::Setup( Camera& camera, double timeS ) {
	SetBackgroundColor( Vec3(0.3, 0.3, 0.3) );

	camera.SetOrigin( Vec3( cos(timeS), 0, sin(timeS) ) );
	camera.RotateYX( DEG2RAD( 1.3 * sin(timeS) ) );

	Vec3 pos1( -0.3, 0.0, 3.2 ), pos2( 2.6, -0.2, 5.5 );

	ObjectSphere* s1 = new ObjectSphere( pos1, 0.5 );
	s1->material = new MaterialNormalMap();

	ObjectSphere* s2 = new ObjectSphere( pos2, 0.8 );
	s2->material = new MaterialPhong;
	s2->material->reflective = 0.70;
	s2->material->SetSurfaceColor( Vec3( 0.8, 0.8, 0.8) );
	s2->material->SetDiffuseCoefficient( 0.8 );
	s2->material->SetSpecularCoefficient( 1.0 );

	ObjectPlane *p1 = new ObjectPlane();
	p1->SetPosition( Vec3 (0, -1,  0) );
	p1->SetNormal( Vec3 (0, -1,  0) );
	p1->SetR( Vec3(1, 0,  0) );

	p1->material = new MaterialPhongCheckmate;
	p1->material->SetColor1( Vec3( 0.2, 0, 0 ) );
	p1->material->SetColor2( Vec3( 1 ) );
	p1->material->cellSize = 1;
	p1->material->reflective = 0.2;
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
//	SetObject( p1 );
}

