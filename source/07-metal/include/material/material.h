#ifndef MATERIAL_H
#define MATERIAL_H

/*
 * 1、生成散射后的光线(或者说它吸收了入射光线)
 * 2、如果发生散射, 决定光线会变暗多少（attenuate）
 */
#include "hittable\hittable.h"
#include "rtweekend\rtweekend.h"
#include "ray\ray.h"


/*
* 在函数中使用 hit_record 作为传入参数，就可以不用传入一大堆变量
* 当然如果你想传一堆变量进去的话也行，这也是个人喜好
*/
struct hit_record;

class material {
public:
    virtual bool scatter(
        const ray& r_in,
        const hit_record& rec,
        color& attenuation,
        ray& scattered
    ) const = 0;
};


class lambertian : public material {
public:
    lambertian(const color& a);

    virtual bool scatter(
        const ray& r_in,
        const hit_record& rec,
        color& attenuation,// 衰减
        ray& scattered// 散射
    ) const override;

public:
    color albedo;// 反射率
};


class metal : public material {
public:
    metal(const color& a, double f);

    virtual bool scatter(
        const ray& r_in,
        const hit_record& rec,
        color& attenuation,
        ray& scattered
    ) const override;

public:
    color albedo;
    double fuzz;// 模糊度
};

#endif
