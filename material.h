#ifndef MATERIAL_H
#define MATERIAL_H

#include "hittable.h"
#include "rtweekend.h"
#include "ray.h"

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
    double fuzz;
};


class dielectric : public material {
public:
    dielectric(double index_of_refraction);

    virtual bool scatter(const ray& r_in,
        const hit_record& rec, color& attenuation, ray& scattered) const override;

public:
    double ir;

private:
    static double reflectance(double cosine, double ref_idx);

};

#endif
