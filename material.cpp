#include "material.h"

lambertian::lambertian(const color& a) : albedo(a) {}

bool lambertian::scatter(const ray& r_in,
    const hit_record& rec, color& attenuation, ray& scattered) const {
    auto scatter_direction = rec.normal + random_unit_vector();

    // Catch degenerate scatter direction
    if (scatter_direction.near_zero()) {
        scatter_direction = rec.normal;
    }

    scattered = ray(rec.p, scatter_direction);
    attenuation = albedo;

    return true;
}


metal::metal(const color& a, double f) : albedo(a), fuzz(f < 1 ? f : 1) {}

bool metal::scatter(const ray& r_in,
    const hit_record& rec, color& attenuation, ray& scattered) const {
    vec3 reflected = reflect(unit_vector(r_in.direction()), rec.normal);
    scattered = ray(rec.p, reflected);
    attenuation = albedo;

    return (dot(scattered.direction(), rec.normal) > 0);
}