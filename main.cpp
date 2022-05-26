#include <iostream>

int main() {
    int nx = 200;
    int ny = 100;

    /*
    * PPM 图像格式分为两部分，分别为头部分和图像数据部分
    * 头部分：由3部分组成，通过换行或空格进行分割，一般 PPM 的标准是空格
    * 第 1 部分：P3 或 P6，指明 PPM 的编码格式
    * 第 2 部分：图像的宽度和高度，通过 ASCII 表示
    * 第 3 部分：最大像素值，0-255 字节表示
    */
    std::cout << "P3\n" << nx << " " << ny << "\n255\n";
    for (int j = ny - 1; j >= 0; --j) {
        for (int i = 0; i < nx; ++i) {
            float r = float(i) / float(nx);
            float g = float(j) / float(ny);
            float b = 0.2;
            int ir = int(255.99 * r);
            int ig = int(255.99 * g);
            int ib = int(255.99 * b);
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }
    
    std::cin.get();
    
    return 0;
}