#ifndef MATERIAL_H
#define MATERIAL_H

#include "hittable.h"
#include "rtweekend.h"
#include "ray.h"

/*
* 在函数中使用 hit_record 作为传入参数，就可以不用传入一大堆变量
* 当然如果你想传一堆变量进去的话也行，这也是个人喜好
*/
struct hit_record;


class material {
public:
    virtual bool scatter(const ray& r_in,
        const hit_record& rec, color& attenuation, ray& scattered) const = 0;
};


class lambertian : public material {
public:
    lambertian(const color& a);

    virtual bool scatter(const ray& r_in,
        const hit_record& rec, color& attenuation, ray& scattered) const override;

public:
    color albedo;
};


class metal : public material {
public:
    metal(const color& a, double f);

    virtual bool scatter(const ray& r_in,
        const hit_record& rec, color& attenuation, ray& scattered) const override;

public:
    color albedo;
    double fuzz;// 模糊度
};

#endif
