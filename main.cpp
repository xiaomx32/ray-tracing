#include "rtweekend.h"
#include "color.h"
#include "hittable_list.h"
#include "sphere.h"

#include <iostream>

double hit_sphere(const point3& center, double radius, const ray& r);
color ray_color(const ray& r, const hittable& world);

int main() {

    // image
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    const int image_height = static_cast<int>(image_width / aspect_ratio);

    // World
    hittable_list world;
    world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
    // 在（0, -100.5, -1）处，放置一个球
    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));

    // Camera
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = point3(0, 0, 0);
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);

    // Render
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto u = double(i) / (double)(image_width - 1);
            auto v = double(j) / (double)(image_height - 1);
            ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
            color pixel_color = ray_color(r, world);
            write_color(std::cout, pixel_color);
        }
    }

    std::cerr << "\nDone.\n";
    std::cin.get();

    return 0;
}

// 计算球体表面与射线的交点以及该点的法线
// 直接将法相值作为颜色输出
// 只需要计算离射线原点最近的那个交点的法相就行了, 后面的东西会被遮挡
double hit_sphere(const point3& center, double radius, const ray& r) {// 直线与球的交点
    vec3 oc = r.origin() - center;// 射线的起点、球心
    //auto a = dot(r.direction(), r.direction());
    //auto b = 2.0 * dot(oc, r.direction());
    //auto c = dot(oc, oc) - radius * radius;
    //auto discriminant = b * b - 4 * a * c;
    auto a = r.direction().length_squared();
    auto half_b = dot(oc, r.direction());
    auto c = oc.length_squared() - radius * radius;
    auto discriminant = half_b * half_b - a * c;

    if (discriminant < 0.0) {
        return -1.0;
    }
    else {
        return (-half_b - sqrt(discriminant)) / a;
    }

    return 0.0;
}

// 使用红色的线表示射线击中（0, 0, -1）处的小球
color ray_color(const ray& r, const hittable& world) {
    hit_record rec;
    if (world.hit(r, 0, infinity, rec)) {
        return 0.5 * (rec.normal + color(1, 1, 1)); 
    }

    // 背景色
    vec3 unit_direction = unit_vector(r.direction());
    auto t = 0.5 * (unit_direction.y() + 1.0);

    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}
