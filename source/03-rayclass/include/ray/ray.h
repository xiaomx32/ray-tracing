#ifndef RAY_H
#define RAY_H

/*
* ����׷�����ĺ����Ǵ����ط�������, ��������Щ���ߵõ�����ɫ
* 1�������ߴ��ӵ�ת��Ϊ��������
* 2����������Ƿ��볡���е������ཻ
* 3�������, ���㽻�����ɫ
* ��������׷�����ĳ���, ��Ū����������ô�����������
* ��Ҳ���дһ���򵥵� color(ray) ���������ر�����ɫֵ��һ���򵥵Ľ���ɫ��
*/
#include "vec3/vec3.h"

class ray {

public:
    ray();
    ray(const point3& origin, const vec3& direction);

    point3 origin() const;
    vec3 direction() const;

    point3 at(double t) const;

public:
    point3 orig;
    vec3 dir;
};
#endif
