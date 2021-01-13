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
#include "../Scene4.h"
#include "../Scene5.h"

#define FILE_NAME_LEN 32

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
	char fileName[FILE_NAME_LEN];
	memset( fileName, 0, FILE_NAME_LEN );

	for( uint32_t i = 1; i <= framesCount; i++ ) {
		Scene4 scene;
		scene.Setup( cam, currentTimeMs / 1000.0 );
		currentTimeMs += frameTimeMs;

		sprintf( fileName, "frames/%u.ppm", i+10000 );
		fileName[7] = '0';

		Canvas canvas( width, height, fileName );
		rend.MakeImage( canvas, scene, cam );

		printf("Frame %u/%u\n", i, framesCount);
		memset( fileName, 0, FILE_NAME_LEN );
	}
}

