#ifndef VEC3_H
#define VEC3_H

#include <cmath>
#include <iostream>

// 向量类
class vec3 {

public:
	// 构造函数，用于初始化 vec3 类
	vec3();
	vec3(double e0, double e1, double e2);

	// 用于接收 e 的值，在编程时可以直接使用（x，y，z）更利于明白意思
	double x() const;
	double y() const;
	double z() const;

	// 重载运算符，定义 vec3 有关的操作
	vec3 operator-() const;
	double operator[](int i) const;
	double& operator[](int i);

	vec3& operator+=(const vec3& v);
	vec3& operator*=(const double t);
	vec3& operator/=(const double t);

	double length_squared() const;
	double length() const;

public:
	double e[3];

};

// 取别名
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

#endif

/*
* 1、构造函数
* 2、重载运算符
*		相当于一个函数，形参个数等于运算符参与对象个数
* 3、返回一个值的引用
* 4、类内部的成员函数是自动 inline 的
*/