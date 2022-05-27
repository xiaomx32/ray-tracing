#ifndef RAY_H
#define RAY_H

/*
* 光线追踪器的核心是从像素发射射线, 并计算这些射线得到的颜色
* 1、将射线从视点转化为像素坐标
* 2、计算光线是否与场景中的物体相交
* 3、如果有, 计算交点的颜色
* 在做光线追踪器的初期, 先弄个简单摄像机让代码能跑起来
* 我也会编写一个简单的 color(ray) 函数来返回背景颜色值（一个简单的渐变色）
*/
#include "vec3.h"

class ray {

public:
    ray();
    ray(const point3& origin, const vec3& direction);

    point3 origin() const;
    vec3 direction() const;

    point3 at(double t) const;

public:
    point3 orig;
    vec3 dir;
};

#endif