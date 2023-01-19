#include <color\color.h>

void write_color(std::ostream& out, color pixel_color) {
	// write the translated [0, 255] value of each color component.
	out << static_cast<int>(255.999 * pixel_color.x()) << " "
		<< static_cast<int>(255.999 * pixel_color.y()) << " "
		<< static_cast<int>(255.999 * pixel_color.z()) << "\n";
}