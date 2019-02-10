#pragma once
#include "vec3.h"

class Ray
{
private:
	vec3 A;	// start point of ray
	vec3 B;	// direction of ray
public:
	Ray();
	Ray(const vec3& a, const vec3& b) { A = a; B = b; }
	vec3 Origin() const { return A; }
	vec3 Direction() const { return B; }
	vec3 PointAt(float t) const { return A + t * B; }
};
