#include <iostream>

int main() {
    const int image_width = 200;
    const int image_height = 100;

    std::cout << "P3\n"
              << image_width << " " << image_height << "\n255\n";
    
    for (int j = image_height - 1; j >= 0; --j) {
        for (int i = 0; i < image_width; ++i) {
            float r = float(i) / float(image_width);
            float g = float(j) / float(image_height);
            float b = 0.2;
            int ir = static_cast<int>(255.99 * r);
            int ig = static_cast<int>(255.99 * g);
            int ib = static_cast<int>(255.99 * b);
            std::cout << ir << " " << ig << " " << ib << "\n";
        }
    }

    std::cin.get();
    
    return 0;
}