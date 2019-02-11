#pragma once
#include <math.h>
#include <stdlib.h>
#include <iostream>

class vec3
{
public:
	float vec[3];
	vec3() {};
	vec3(float x, float y, float z) { vec[0] = x; vec[1] = y; vec[2] = z; };
	~vec3() {};

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



	inline float Length() const { return sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]); }
	inline float SquaredLength() const { return vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]; }
	inline void MakeUnitVector();

};


inline std::istream& operator>>(std::istream &is, vec3 &t)
{
	is >> t.vec[0] >> t.vec[1] >> t.vec[2];
	return is;
}



inline std::ostream& operator<<(std::ostream &os, const vec3 &t)
{
	os << t.vec[0] << " " << t.vec[1] << " " << t.vec[2];
	return os;
}



inline void vec3::MakeUnitVector()
{
	float k = 1.0 / sqrt(vec[0] * vec[0] + vec[1] * vec[1] + vec[2] * vec[2]);
	vec[0] *= k; vec[1] *= k; vec[2] *= k;
}



inline vec3 operator+(const vec3 &v1, const vec3 &v2)
{
	return vec3(v1.vec[0] + v2.vec[0], v1.vec[1] + v2.vec[1], v1.vec[2] + v2.vec[2]);
}



inline vec3 operator-(const vec3 &v1, const vec3 &v2)
{
	return vec3(v1.vec[0] - v2.vec[0], v1.vec[1] - v2.vec[1], v1.vec[2] - v2.vec[2]);
}



inline vec3 operator*(const vec3 &v1, const vec3 &v2)
{
	return vec3(v1.vec[0] * v2.vec[0], v1.vec[1] * v2.vec[1], v1.vec[2] * v2.vec[2]);
}



inline vec3 operator/(const vec3 &v1, const vec3 &v2)
{
	return vec3(v1.vec[0] / v2.vec[0], v1.vec[1] / v2.vec[1], v1.vec[2] / v2.vec[2]);
}



inline vec3 operator*(float t, const vec3 &v)
{

	return vec3(t*v.vec[0], t*v.vec[1], t*v.vec[2]);
}



inline vec3 operator/(vec3 v, float t)
{
	return vec3(v.vec[0] / t, v.vec[1] / t, v.vec[2] / t);
}



inline vec3 operator*(const vec3 &v, float t)
{
	return vec3(t*v.vec[0], t*v.vec[1], t*v.vec[2]);
}



inline float dot(const vec3 &v1, const vec3 &v2)
{
	return v1.vec[0] * v2.vec[0] + v1.vec[1] * v2.vec[1] + v1.vec[2] * v2.vec[2];
}



inline vec3 cross(const vec3 &v1, const vec3 &v2)
{
	return vec3((v1.vec[1] * v2.vec[2] - v1.vec[2] * v2.vec[1]),
		(-(v1.vec[0] * v2.vec[2] - v1.vec[2] * v2.vec[0])),
		(v1.vec[0] * v2.vec[1] - v1.vec[1] * v2.vec[0]));
}





inline vec3& vec3::operator+=(const vec3 &v)
{
	vec[0] += v.vec[0];
	vec[1] += v.vec[1];
	vec[2] += v.vec[2];
	return *this;
}



inline vec3& vec3::operator*=(const vec3 &v)
{
	vec[0] *= v.vec[0];
	vec[1] *= v.vec[1];
	vec[2] *= v.vec[2];
	return *this;
}



inline vec3& vec3::operator/=(const vec3 &v)
{

	vec[0] /= v.vec[0];
	vec[1] /= v.vec[1];
	vec[2] /= v.vec[2];
	return *this;

}



inline vec3& vec3::operator-=(const vec3& v)
{

	vec[0] -= v.vec[0];
	vec[1] -= v.vec[1];
	vec[2] -= v.vec[2];
	return *this;
}



inline vec3& vec3::operator*=(const float t)
{

	vec[0] *= t;
	vec[1] *= t;
	vec[2] *= t;
	return *this;
}



inline vec3& vec3::operator/=(const float t)
{
	float k = 1.0 / t;

	vec[0] *= k;
	vec[1] *= k;
	vec[2] *= k;
	return *this;
}



inline vec3 UnitVector(vec3 v)
{
	return v / v.Length();
}