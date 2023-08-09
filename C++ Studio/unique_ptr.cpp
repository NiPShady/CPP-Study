#include<iostream>
#include<memory>
#include<string>
#include "unique_ptr.h"

class Entity
{	
public:
	Entity() {
		std::cout << "Create Entity!" << std::endl;
	}
	~Entity()
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}
	void Print(){}
};

int main()
{
	{
		std::shared_ptr<Entity> e0;//在sharedEntity所在的控制域死亡后,e0依然可以指向sharedEntity指向的内存,直到e0所在的控制域死亡e0被自动销毁
		//大括号制作新的控制域
		{
			//格式为std::unique_ptr <模板/类> 变量名 = std::make_unique<模板/类>();
			std::unique_ptr<Entity> entity = std::make_unique<Entity>(); //unique_ptr分配时不允许隐式变量转换,必须显式调用构造函数 同时使用std::make_unique保证安全性(在构造函数抛出异常时不会返回没有引用的悬空指针以导致内存泄露)

			entity->Print(); //在作用域内可以像普通指针一样使用unique_ptr,离开作业域指针entity会自动销毁,但是不可以复制unique_ptr,这会使原指针在销毁后复制指针成为野指针造成内存泄露
			//需要传递unique_ptr时使用std::shared_ptr,而不是将unique_ptr赋给新指针
			//std::shared_ptr采用引用计数,当指针引用为零时,自动销毁shared_ptr
			//格式为std::shared_ptr <模板/类> 变量名 = std::make_shared<模板/类>();
			std::shared_ptr<Entity> sharedEntity = std::make_shared<Entity>(); //std::shared_ptr中不使用new关键词是应为shared_ptr需要分配另一块内存(控制块)存储引用计数,而使用new关键字会导致2次内存分配
			e0 = sharedEntity;
			//shared_ptr赋值给shared_ptr时会增加引用计数,但是赋值给weak_ptr时不会
			//weak_ptr弱指针,不会增加shared_ptr的引用计数,但同样weak_ptr也不会和shared_ptr一样存活
			std::weak_ptr<Entity> weakEntity = sharedEntity;  //weak_ptr可以被询问是否有效(是否指向为空)

		}
	}
	std::cin.get();
}