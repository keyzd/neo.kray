#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NeoKray.h"

#include "Canvas.h"
#include "Ray.h"
#include "ObjectSphere.h"
#include "IRenderer.h"
#include "DefaultRenderer.h"
#include "ICamera.h"
#include "CameraPinhole.h"

#include "../Scene1.h"
#include "../Scene2.h"
#include "../Scene3.h"

NeoKray::NeoKray( int argc, char *argv[] ) {
	ReadCmdArgs( argc, argv );
	InitTimeLine();
}

void NeoKray::ReadCmdArgs( int argc, char *argv[] ) {
	if( argc < 5 ) {
		printf( "Usage: ./nkray [WIDTH] [HEIGHT] [DURATION_MS] [FPS]\n" );
		exit( 1 );
	}

	width = atoi( argv[ 1 ] );
	height = atoi( argv[ 2 ] );
	durationMs = atoi( argv[ 3 ] );
	fps = atoi( argv[ 4 ] );
}

void NeoKray::InitTimeLine() {
	frameTimeMs = 1000.0 / double( fps );
	framesCount = fps * durationMs / 1000;
	currentTimeMs = 0;
}

void NeoKray::MainLoop() {
	DefaultRenderer rend;
	CameraPinhole cam( width, height );
	char fileName[16];
	memset( fileName, 0, 16 );

	for( uint32_t i = 1; i <= framesCount; i++ ) {
		Scene3 scene;
		scene.Setup( cam, currentTimeMs / 1000.0 );
		currentTimeMs += frameTimeMs;

		sprintf( fileName, "%u.ppm", i+10000 );
		fileName[0] = '0';

		Canvas canvas( width, height, fileName );
		rend.MakeImage( canvas, scene, cam );

		printf("Frame %u/%u\n", i, framesCount);
		memset( fileName, 0, 16 );
	}
}

