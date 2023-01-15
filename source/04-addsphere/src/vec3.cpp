#include "vec3\vec3.h"

vec3::vec3() : e{ 0.0f, 0.0f, 0.0f } {}

vec3::vec3(double e0, double e1, double e2) : e{ e0, e1, e2 } {}

double vec3::x() const { return e[0]; }

double vec3::y() const { return e[1]; }

double vec3::z() const { return e[2]; }

vec3 vec3::operator-() const {// 定义负号的意义
	return vec3(-e[0], -e[1], -e[2]);
}

double vec3::operator[](int i) const {// 取值
	return e[i];
}

double& vec3::operator[](int i) {// 加引用，可以修改值
	return e[i];
}

vec3& vec3::operator+=(const vec3& v) {
	e[0] += v.e[0];// "." 运算符来访问 v 对象的成员
	e[1] += v.e[1];
	e[2] += v.e[2];

	return *this;
}

vec3& vec3::operator*=(const double t) {
	e[0] *= t;
	e[1] *= t;
	e[2] *= t;

	return *this;
}

vec3& vec3::operator/=(const double t) {
	return *this *= 1 / t;
}

double vec3::length_squared() const {// 向量模的平方
	return e[0] * e[0] + e[1] * e[1] + e[2] * e[2];
}

double vec3::length() const {// 向量的模
	return std::sqrt(length_squared());
}


// 非成员函数
std::ostream& operator<<(std::ostream& out, const vec3& v) {
	return out << v.e[0] << ' ' << v.e[1] << ' ' << v.e[2];
}

vec3 operator+(const vec3& u, const vec3& v) {
	return vec3(u.e[0] + v.e[0], u.e[1] + v.e[1], u.e[2] + v.e[2]);
}

vec3 operator-(const vec3& u, const vec3& v) {
	return vec3(u.e[0] - v.e[0], u.e[1] - v.e[1], u.e[2] - v.e[2]);
}

vec3 operator*(const vec3& u, const vec3& v) {
	return vec3(u.e[0] * v.e[0], u.e[1] * v.e[1], u.e[2] * v.e[2]);
}

vec3 operator*(double t, const vec3& v) {// 向量数乘
	return vec3(t * v.e[0], t * v.e[1], t * v.e[2]);
}

vec3 operator*(const vec3& v, double t) {
	return t * v;
}

vec3 operator/(vec3 v, double t) {
	return (1 / t) * v;
}

double dot(const vec3& u, const vec3& v) {// 点乘
	return u.e[0] * v.e[0] + u.e[1] * v.e[1] + u.e[2] * v.e[2];
}

vec3 cross(const vec3& u, const vec3& v) {// 叉乘
	return vec3(u.e[1] * v.e[2] - u.e[2] * v.e[1],
		u.e[2] * v.e[0] - u.e[0] * v.e[2],
		u.e[0] * v.e[1] - u.e[1] * v.e[0]);
}

vec3 unit_vector(vec3 v) {// 单位化
	return v / v.length();
}