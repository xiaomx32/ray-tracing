#ifndef SPHERE_H
#define SPHERE_H

#include "hittable\hittable.h"
#include "vec3\vec3.h"

class sphere : public hittable {
public:
	sphere();
	sphere(point3 cen, double r);

	virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;

public:
	point3 center;
	double radius = 0.0;

};
#endif
