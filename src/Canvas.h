/*
 *	Canvas exports Portable PixMap file (0-255 colors for each RGB channel)
 *	NOTE: color represents in 3d-vector with normalized components (0.0-1.0)
 */

#ifndef CANVAS_H
#define CANVAS_H

#include <stdio.h>
#include <stdint.h>

#include "Vec3.h"

class Canvas {
public:
	Canvas( const uint32_t a_width, const uint32_t a_height, const char* file_ppm_path );
	~Canvas();

	inline uint32_t GetWidth() const;
	inline uint32_t GetHeight() const;

	void SetPixel( Vec3 pixel, uint32_t x, uint32_t y );
	Vec3 GetPixel( uint32_t x, uint32_t y ) const;

private:
	Vec3 *pixel_buf;
	FILE *file_ppm;
	uint32_t width, height;

	void WriteBufferToFile();
	void WritePixelToFile(Vec3 pixel);
};

inline uint32_t Canvas::GetWidth() const {
	return width;
}

inline uint32_t Canvas::GetHeight() const {
	return height;
}

#endif
