#include "camera.h"

camera::camera(
    point3 lookfrom,// 相机所在位置，相机在 lookfrom 位置看向 lookat 点
    point3 lookat,// 相机视线指向的位置点
    vec3 vup,
    double vfov,// top to bottom, in degrees
    double aspect_ratio,// 屏幕宽高比
    double aperture,// 光圈
    double focus_dist
) {// vertical field-of-view in degrees

    auto theta = degrees_to_radians(vfov);
    auto h = tan(theta / 2);// 眼睛离屏幕中心的距离为 -1
    auto viewport_height = 2.0 * h;// 视口高度
    auto viewport_width = aspect_ratio * viewport_height;// 视口宽度

    // 确定三维正交相机坐标系 (u, v, w)
    // 相机平面是过 lookfrom 垂直于视线（from->at）的一个平面

    w = unit_vector(lookfrom - lookat);// w 是一个正交于相机平面的基向量（与视线相反的基向量）
    u = unit_vector(cross(vup, w));// u 代表相机平面的水平向量，u 一定平行于世界坐标系的 x 轴
    v = cross(w, u);// 叉乘定义 v，垂直于相机平面的方向

    origin = lookfrom;
    horizontal = focus_dist * viewport_width * u;
    vertical = focus_dist * viewport_height * v;
    lower_left_corner = origin - horizontal / 2 - vertical / 2 - focus_dist * w;

    lens_radius = aperture / 2;
}

/*
* ray camera::get_ray(double s, double t) const {
*     return ray(origin, lower_left_corner + s * horizontal + t * vertical - origin);
* }
*/

ray camera::get_ray(double s, double t) const {
    vec3 rd = lens_radius * random_in_unit_disk();
    vec3 offset = u * rd.x() + v * rd.y();

    return ray(
        origin + offset,
        lower_left_corner + s * horizontal + t * vertical - origin - offset
    );
}
