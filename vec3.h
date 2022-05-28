#ifndef VEC3_H
#define VEC3_H

#include "rtweekend.h"
#include <cmath>
#include <iostream>

class vec3 {

public:
	vec3();
	vec3(double e0, double e1, double e2);

	double x() const;
	double y() const;
	double z() const;

	vec3 operator-() const;
	double operator[](int i) const;
	double& operator[](int i);

	vec3& operator+=(const vec3& v);
	vec3& operator*=(const double t);
	vec3& operator/=(const double t);

	double length_squared() const;
	double length() const;

	static vec3 random();
	static vec3 random(double min, double max);

	bool near_zero() const;

public:
	double e[3];

};

using point3 = vec3;
using color = vec3;


std::ostream& operator<<(std::ostream& out, const vec3& v);

vec3 operator+(const vec3& u, const vec3& v);

vec3 operator-(const vec3& u, const vec3& v);

vec3 operator*(const vec3& u, const vec3& v);

vec3 operator*(double t, const vec3& v);

vec3 operator*(const vec3& v, double t);

vec3 operator/(vec3 v, double t);

double dot(const vec3& u, const vec3& v);

vec3 cross(const vec3& u, const vec3& v);

vec3 unit_vector(vec3 v);

vec3 random_in_unit_sphere();

vec3 random_unit_vector();

vec3 random_in_hemisphere(const vec3& normal);

vec3 reflect(const vec3& v, const vec3& n);

vec3 refract(const vec3& uv, const vec3& n, double etai_over_etat);

vec3 random_in_unit_disk();

#endif
