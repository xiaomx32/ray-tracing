#ifndef HITTABLE_LIST_H
#define HITTABLE_LIST_H

#include "hittable.h"
#include <memory>// 智能指针 std::shared_ptr
#include <vector>

using std::shared_ptr;
using std::make_shared;

class hittable_list : public hittable {
public:
	hittable_list();
	hittable_list(shared_ptr<hittable> object);

	void clear();
	void add(shared_ptr<hittable> object);

	virtual bool hit(const ray& r, double t_min, double t_max, hit_record& rec) const override;

public:
	std::vector<shared_ptr<hittable>> objects;
};

#endif

/*
* shared_ptr 智能指针
* shared_ptr 类描述一个对象，该对象使用引用计数来管理资源
* shared_ptr 对象有效保留一个指向其拥有的资源的指针或保留一个 null 指针
* 资源可由多个 shared_ptr 对象拥有；当拥有特定资源的最后一个 shared_ptr 对象被销毁后，资源将释放
* shared_ptr重新分配或重置资源时，停止拥有资源。
*
* 智能指针首先由一个刚刚新分配好内存的物体来初始化
*
* make_shared<thing>(thing_constructor_params ...) 为指定的类型分配一段内存,
* 使用你指定的构造函数与参数来创建这个类, 并返回一个智能指针 shared_ptr<thing>
*
* 在代码中使用智能指针的目的是为了能让多个几何图元共享一个实例
* (举个栗子, 一堆不同球体使用同一个纹理材质), 并且这样内存管理比起普通的指针更加的简单方便
*/
