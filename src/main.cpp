#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "NeoKray.h"

int main( int argc, char *argv[] ) {
	NeoKray app( argc, argv );
	app.MainLoop();
	return 0;
}
