#include "src/Light.h"
#include "src/IObject.h"
#include "src/ObjectSphere.h"
#include "src/ObjectCylinder.h"
#include "src/ObjectPlane.h"
#include "src/MaterialPhong.h"
#include "src/MaterialNormalMap.h"
#include "src/MaterialNormalMap2.h"
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
	camera.RotateYZ( DEG2RAD( sin(timeS) ) );

	float z1 = 3.0;
	float z2 = 3.0;
	float z3 = 3.0;
	float z4 = 3.0;

	float r1 =  0.6, r2 = 0.6, r3 = 0.8, r4 = 0.8;

	Vec3 pos1( 1.6*sin(timeS)*-1, -5+r1 + sin(timeS*3)+1 + sin(timeS*0.7), 1.6*cos(timeS)*-1 + z1 ),
		 pos2( 1.6*sin(timeS), -5+r2 + cos(timeS*3)+1 + sin(timeS*0.7), 1.6*cos(timeS) + z2 ),

		 pos3( 2.7*cos(timeS), -5+r3 + cos(timeS*3)+1 + sin(timeS*0.7), 2.7*sin(timeS) + z3 ),
		 pos4( 2.7*cos(timeS)*-1, -5+r4 + sin(timeS*3)+1 + sin(timeS*0.7), 2.7*sin(timeS) + z4 );

	ObjectSphere* s1 = new ObjectSphere( pos1, r1 );
	s1->material = new MaterialPhong;
	s1->material->reflective = 0.70*sin(timeS);
	s1->material->SetSurfaceColor( Vec3( 0.6, 0.4, 0.8) );
	s1->material->SetDiffuseCoefficient( 0.8*fabsf(sin(timeS)) );
	s1->material->SetSpecularCoefficient( 1.0 );

	ObjectSphere* s2 = new ObjectSphere( pos2, r2 );
	s2->material = new MaterialPhong;
	s2->material->reflective = 0.70*cos(timeS);
	s2->material->SetSurfaceColor( Vec3( 0.9, 0.5, 0.4) );
	s2->material->SetDiffuseCoefficient( 0.8*fabsf(cos(timeS)) );
	s2->material->SetSpecularCoefficient( 1.0 );

	ObjectSphere* s3 = new ObjectSphere( pos3, r3 );
	s3->material = new MaterialNormalMap;

	ObjectSphere* s4 = new ObjectSphere( pos4, r4 );
	s4->material = new MaterialNormalMap2;

	ObjectPlane *p1 = new ObjectPlane;
	p1->SetPosition( Vec3 (0, -5 + sin(timeS*0.7),  0) );
	p1->SetNormal( Vec3 (0, -1,  0) );
	p1->SetR( Vec3(1, 0,  0) );

	p1->material = new MaterialPhongCheckmate;
	p1->material->SetColor1( Vec3( 0.2, 0, 0 ) );
	p1->material->SetColor2( Vec3( 1 ) );
	p1->material->cellSize = 2;
	p1->material->reflective = 0.2;
	p1->material->SetSurfaceColor( Vec3(1, 1,  1) );
	p1->material->SetDiffuseCoefficient( -1.0 );
	p1->material->SetSpecularCoefficient( 0.0 );

	ObjectPlane *p2 = new ObjectPlane;
	p2->SetPosition( Vec3 (0, 0,  5) );
	p2->SetNormal( Vec3 (0, 0,  1) );
//	p2->SetR( Vec3(1, 0,  0) );

	p2->material = new MaterialPhongCheckmate;
	p2->material->SetColor1( Vec3( 0.0, 0.0, 0.3 ) );
	p2->material->SetColor2( Vec3( 1 ) );
	p2->material->cellSize = 5;
	p2->material->reflective = 0.7;
	p2->material->SetSurfaceColor( Vec3(1, 1,  1) );
	p2->material->SetDiffuseCoefficient( -1.0 );
	p2->material->SetSpecularCoefficient( 0.0 );

	Light* l1 = new Light( LightType::point );
	l1->SetIntensity( 0.8 );
	l1->SetSpecularCoefficient( 100 );
	l1->SetLightPosition( Vec3(0.0, 0.0, 0.0) );

	SetLight( l1 );
	SetObject( s1 );
	SetObject( s2 );
	SetObject( s3 );
	SetObject( s4 );
	SetObject( p1 );
//	SetObject( p2 );
}

