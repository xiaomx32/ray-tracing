#include "hittable.h"

hit_record::hit_record() : t(0.0), front_face(false) {}

void hit_record::set_face_normal(const ray& r, const vec3& outward_normal) {
	// 利用点乘，判断法线与光线的方向
	// 同向：光线从物体内部射向物体表面
	// 反向：光线从物体外部射向物体表面
	front_face = dot(r.direction(), outward_normal) < 0;
	normal = front_face ? outward_normal : -outward_normal;
}
