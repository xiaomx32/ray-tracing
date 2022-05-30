#include "color.h"

/*
* 不在每次发出射线采样时都计算一个 0-1 之间的颜色值,
* 而是一次性把所有的颜色都加在一起然后最后只需要简单的除以采样点个数
* 另外, 给头文件 rtweekend.h 加入了一个新函数 clamp(x, min, max), 用来将 x 限制在 [min,max] 区间之中
*/
void write_color(std::ostream& out, color pixel_color, int samples_per_pixel) {
    auto r = pixel_color.x();
    auto g = pixel_color.y();
    auto b = pixel_color.z();

    // Divide the color by the number of samples.
    auto scale = 1.0 / samples_per_pixel;
    r *= scale;
    g *= scale;
    b *= scale;

    // Write the translated [0,255] value of each color component.
    out << static_cast<int>(256 * clamp(r, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(g, 0.0, 0.999)) << ' '
        << static_cast<int>(256 * clamp(b, 0.0, 0.999)) << '\n';
}