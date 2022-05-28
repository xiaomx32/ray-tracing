#ifndef HITTABLE_H
#define HITTABLE_H

#include "ray.h"
#include "rtweekend.h"

class material;

/*
* 光线会如何与表面交互是由具体的材质所决定的
* hit_record 在设计上就是为了把一堆要传的参数给打包在了一起
* 当光线射入一个表面（比如一个球体）, hit_record 中的材质指针会被球体的材质指针所赋值
* 而球体的材质指针是在 main() 函数中构造时传入的
* 当 color() 函数获取到 hit_record 时, 他可以找到这个材质的指针, 然后由材质的函数来决定光线是否发生散射, 怎么散射
*/
struct hit_record {
	hit_record();
	vec3 p;
	vec3 normal;
	shared_ptr<material> mat_ptr;// 材质指针
	double t;
	bool front_face;

	void set_face_normal(const ray& r, const vec3& outward_normal);
};

class hittable {
public:

	virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const = 0;

};
#endif
