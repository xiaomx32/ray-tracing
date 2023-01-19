#include <rtweekend\rtweekend.h>
#include <hittable\hittable_list.h>
#include <sphere\sphere.h>

#include <iostream>

color ray_color(const ray& r, const hittable& world);

int main() {
    // image
    const int image_width = 200;
    const int image_height = 100;

    // World
    hittable_list world;
    world.add(make_shared<sphere>(point3(0, 0, -1), 0.5));
    world.add(make_shared<sphere>(point3(0, -100.5, -1), 100));// 在（0, -100.5, -1）处，放置一个球

    // Camera
    vec3 lower_left_corner(-2.0, -1.0, -1.0);
    vec3 horizontal(4.0, 0.0, 0.0);
    vec3 vertical(0.0, 2.0, 0.0);
    vec3 origin(0.0, 0.0, 0.0);

    // Render
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto u = double(i) / (double)(image_width - 1);
            auto v = double(j) / (double)(image_height - 1);
            ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);// 照相机位于(0, 0, 0)
            color pixel_color = ray_color(r, world);
            write_color(std::cout, pixel_color);
        }
    }

    std::cerr << "\nDone.\n";
    std::cin.get();

    return 0;
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
