#ifndef SPHERE_H
#define SPHERE_H

#include "vec3.h"
#include "hittable.h"

class sphere : public hittable {
public:
	sphere();
	sphere(point3 cen, double r, shared_ptr<material> m);

	// override 关键字表示重写父类的虚函数，前面的 virtual 可写可不写
	virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;

public:
	point3 center;
	double radius = 0.0;
	shared_ptr<material> mat_ptr;

};
#endif
