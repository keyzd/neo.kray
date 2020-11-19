#include "Canvas.h"

Canvas::Canvas( uint32_t a_width, uint32_t a_height, const char* file_ppm_path ) {
	width = a_width;
	height = a_height;
	pixel_buf = new Vec3[width * height];
	file_ppm = fopen( file_ppm_path, "w" );
}

Canvas::~Canvas() {
	WriteBufferToFile();
	fclose(file_ppm);
	delete [] pixel_buf;
}

void Canvas::SetPixel( Vec3 pixel, uint32_t x, uint32_t y ) {
	if( pixel.x > 1.0 ) {
		pixel.x = 1.0;
	} else if( pixel.x < 0.0 ) {
		pixel.x = 0.0;
	}

	if( pixel.y > 1.0 ) {
		pixel.y = 1.0;
	} else if( pixel.y < 0.0 ) {
		pixel.y = 0.0;
	}

	if( pixel.z > 1.0 ) {
		pixel.z = 1.0;
	} else if( pixel.z < 0.0 ) {
		pixel.z = 0.0;
	}

	pixel_buf[x + y * width] = pixel;
}

inline Vec3 Canvas::GetPixel( uint32_t x, uint32_t y ) const {
	return pixel_buf[x + y * width];
}

void Canvas::WriteBufferToFile() {
	fprintf( file_ppm, "P3\n" );
	fprintf( file_ppm, "%d %d\n255\n", width, height );

	for( uint32_t y = 0; y < height; y++ ) {
		for( uint32_t x = 0; x < width; x++ ) {
			WritePixelToFile( GetPixel( x, y ) );
		}
	}
}

void Canvas::WritePixelToFile( Vec3 pixel ) {
	uint8_t r = uint8_t( pixel.r * 255. );
	uint8_t g = uint8_t( pixel.g * 255. );
	uint8_t b = uint8_t( pixel.b * 255. );
	fprintf( file_ppm, "%u %u %u\n", r, g, b );
}

