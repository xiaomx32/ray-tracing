#ifndef VEC3_H
#define VEC3_H

#include "rtweekend\rtweekend.h"
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

public:
	double e[3];

};


using point3 = vec3;// 3d point
using color = vec3;// RGB color

// 非成员函数
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

#endif

/*
* 在类声明中声明成员函数时， static 关键字指定该函数由该类的所有实例共享
* static 成员函数无法访问实例成员，因为该函数没有隐式 this 指针
* 若要访问实例成员，需使用实例指针或引用的参数声明函数
*/
