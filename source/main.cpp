#include <vec3/vec3.h>
#include <color/color.h>

#include <iostream>

int main() {
    // image
    const int image_width = 256;
    const int image_height = 256;

    // Render
    // 输出流，可以重定向写入到文件
    std::cout << "P3\n" << image_width << " " << image_height << "\n255\n";

    for (int j = image_height - 1; j >= 0; --j) {
        std::cerr << "\rScanlines remaining: " << j << ' ' << std::flush;
        for (int i = 0; i < image_width; ++i) {
            color pixel_color(double(i) / (double)(image_width - 1), double(j) / (double)(image_height - 1), 0.25);
            write_color(std::cout, pixel_color);
        }
    }
    // 处理错误输出流，无缓冲，只能写到屏幕上，不能重定向写入到文件
    std::cerr << "\nDone.\n";
    std::cin.get();

    return 0;
}