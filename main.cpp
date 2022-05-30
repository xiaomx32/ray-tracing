#include "vec3.h"
#include "color.h"
#include "ray.h"

#include <iostream>

color ray_color(const ray& r);

int main() {
    // image
    const auto aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;
    // 编译器隐式执行的任何类型转换都可以由 static_cast 来完成
    const int image_height = static_cast<int>(image_width / aspect_ratio);// 宽高比为 16 : 9

    // Camera
    auto viewport_height = 2.0;
    auto viewport_width = aspect_ratio * viewport_height;
    auto focal_length = 1.0;

    auto origin = point3(0, 0, 0);// 射线的起点
    auto horizontal = vec3(viewport_width, 0, 0);
    auto vertical = vec3(0, viewport_height, 0);
    auto lower_left_corner = origin - horizontal / 2 - vertical / 2 - vec3(0, 0, focal_length);// 屏幕左下角

    // Render
    // 输出流，可以重定向写入到文件
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            auto u = double(i) / (double)(image_width - 1);
            auto v = double(j) / (double)(image_height - 1);
            ray r(origin, lower_left_corner + u * horizontal + v * vertical - origin);
            color pixel_color = ray_color(r);
            write_color(std::cout, pixel_color);
        }
    }
    // 处理错误输出流，无缓冲，只能写到屏幕上，不能重定向写入到文件
    std::cerr << "\nDone.\n";
    std::cin.get();

    return 0;
}

/*
 * 屏幕坐标系：4 * 2（自定义的）
 * 需要将光线（视线）向量，进行单位化，以保证每个坐标分量的长度控制在 [-1, 1]
 * 因为我们使用 y 轴做渐变, 所以你可以看到这个蓝白渐变也是竖直的
*/

// ray_color(ray) 函数根据 y 值将蓝白做线性插值的混合
color ray_color(const ray& r) {
    vec3 unit_direction = unit_vector(r.direction());// 单位化，此时取值范围是 [-1, 1]
    auto t = 0.5 * (unit_direction.y() + 1.0);// 将 y 分量映射到 [0, 1]
    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}
