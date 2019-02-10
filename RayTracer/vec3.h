#pragma once
#include <math.h>
#include <stdlib.h>
#include <iostream>

class vec3
{
public:
	float vec[3];
	vec3();
	vec3(float x, float y, float z) { vec[0] = x; vec[1] = y; vec[2] = z; };
	~vec3();

	inline float x() const { return vec[0]; }
	inline float y() const { return vec[1]; }
	inline float z() const { return vec[2]; }
									
	inline float r() const { return vec[0]; }
	inline float g() const { return vec[1]; }
	inline float b() const { return vec[2]; }



	inline const vec3& operator+() const { return *this; }
	inline vec3 operator-() const { return vec3(-vec[0], -vec[1], -vec[2]); }
	inline float operator[](int i) const { return vec[i]; }
	inline float& operator[](int i) { return vec[i]; };



	inline vec3& operator+=(const vec3 &v2);
	inline vec3& operator-=(const vec3 &v2);
	inline vec3& operator*=(const vec3 &v2);
	inline vec3& operator/=(const vec3 &v2);
	inline vec3& operator*=(const float t);
	inline vec3& operator/=(const float t);



	inline float length() const { return sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]); }
	inline float squared_length() const { return vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]; }
	inline void make_unit_vector();

};


