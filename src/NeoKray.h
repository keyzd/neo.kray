#ifndef NEO_KRAY_H
#define NEO_KRAY_H

#include <stdint.h>

class NeoKray {
public:
	NeoKray( int argc, char *argv[] );
	void MainLoop();

private:
	void ReadCmdArgs( int argc, char *argv[] );
	void InitTimeLine();

	uint32_t width;
	uint32_t height;
	uint32_t durationMs;
	uint32_t fps;

	double frameTimeMs;
	uint32_t framesCount;
	double currentTimeMs;
};

#endif
