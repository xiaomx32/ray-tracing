#include <vec3/vec3.h>
#include <iostream>


int main() {
    // image
    const int image_width = 200;
    const int image_height = 100;

    // Render
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            vec3 color(double(i)/image_width, double(j)/image_height, 0.2);
            color.write_color(std::cout);
        }
    }

    std::cerr << "\nDone.\n";

    return 0;
}

/*
 * 屏幕坐标系：4 * 2（自定义的）
 * 需要将光线（视线）向量，进行单位化，以保证每个坐标分量的长度控制在 [-1, 1]
 * 因为我们使用 y 轴做渐变, 所以你可以看到这个蓝白渐变也是竖直的
*/

// ray_color(ray) 函数根据 y 值将蓝白做线性插值的混合
color ray_color(const ray& r) {
    /*
    * 原视口高度本身就为 [-1, 1]
    * 因此单位化这一步是错的，得到的结果不是真正的白蓝渐变，可以直接这么写：
    * auto t = 0.5 * (r.direction().y() + 1.0);
    */
    vec3 unit_direction = unit_vector(r.direction());// 单位化，此时取值范围是 [-1, 1]
    auto t = 0.5 * (unit_direction.y() + 1.0);// 将 y 分量映射到 [0, 1]

    return (1.0 - t) * color(1.0, 1.0, 1.0) + t * color(0.5, 0.7, 1.0);
}
