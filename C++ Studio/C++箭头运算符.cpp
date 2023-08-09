#include <iostream>
#include <string>

class Entity
{
public:
	int x;

	void Print()
		const //const标记的重载运算符调用的函数也需要标记const
	{
		std::cout << "Hello !" << std::endl;
	}
};

class ScopedPtr
{
private:
	Entity* m_Obj;
public:
	ScopedPtr(Entity* entity)
	{
	}

	~ScopedPtr()
	{
		delete m_Obj;
	}

	Entity* operator->() //重载'->'箭头运算符使得ScopedPtr类可以访问Entity类
	{
		return m_Obj;
	}

	const Entity* operator->() //重载'->'箭头运算符使得ScopedPtr类可以访问Entity类
		const  //const标记的变量使用'->'重载的const版本,使用const版本时,调用的函数也需要标记为const
	{
		return m_Obj;
	}
};

struct Vector3
{
	float x, y, z;
};

int main()
{
	//Entity e; 
	//e.Print();

	//Entity* ptr = &e;

	//ptr->x = 2;
	//ptr->Print();
	//

	const ScopedPtr entity = new Entity(); //当entity(Class:Entity)超出范围时,ScopedPtr自动销毁entity(Class:Entity)
	entity->Print();//重载'->'箭头操作符

	/*通过箭头操作符获取内存中某个变量的偏移量*/
	
	//地址从0开始
	//首先将nullptr强制转化为Vevtor3指针
	//然后用箭头控制符访问x,得到内存的布局
	//取x的内存地址得到x的偏移量
	//最后转化为int赋值给offset存储x在内存中的偏移量
	int offset = (int)&((Vector3*)nullptr)->x; //offset存储x的偏移量
	std::cout << offset << std::endl;

	std::cin.get();
}