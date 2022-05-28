#include "hittable.h"

hit_record::hit_record() : t(0.0), front_face(false) {}

void hit_record::set_face_normal(const ray& r, const vec3& outward_normal) {// 时间与面朝向
	front_face = dot(r.direction(), outward_normal) < 0;
	normal = front_face ? outward_normal : -outward_normal;
}
