#include <sphere\sphere.h>

sphere::sphere() {}

sphere::sphere(point3 cen, double r) : center(cen), radius(r) {}

bool sphere::hit(const ray& r, double t_min, double t_max, hit_record& rec) const {
    // 球和直线求交方程：
    // p = a + tb; x^{2} + y^{2} + z^{2} = r^{2}
    // t^{2}b^{2} + 2t(b)(a - c) + (a - c)^{2} - r^{2} = 0
    vec3 oc = r.origin() - center;
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - radius * radius;
    auto discriminant = half_b * half_b - a * c;// 判别式

    if (discriminant < 0) { return false; }

    // Find the nearest root that lies in the acceptable range.
    auto sqrtd = sqrt(discriminant);
    auto root = (-half_b - sqrtd) / a;
    if (root < t_min || t_max < root) {
        root = (-half_b + sqrtd) / a;
        if (root < t_min || t_max < root) {
            return false;
        }
    }

    rec.t = root;
    rec.p = r.at(rec.t);
    vec3 outward_normal = (rec.p - center) / radius;// 球的单位法线
    rec.set_face_normal(r, outward_normal);

    return true;
}
