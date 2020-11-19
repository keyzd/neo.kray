#ifndef SHADE_RECORD_H
#define SHADE_RECORD_H

#include "Vec3.h"

struct ShadeRecord {
	Vec3 normal;
	Vec3 hitPoint;
	Vec3 toLightDir;
	Vec3 toCamDir;
	Light *light;
};

#endif
