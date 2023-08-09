#include<iostream>

class Log
{
private:
	//Log() {}//通过设置构造函数为private来拒绝用户访问构造函数
public:
	Log() = delete;//禁用默认构造函数
};

class Entity {
public:
	float X, Y;

	Entity()//构造函数没有返回类型切函数名必须与类名相同
	{
		X = 0.0f;
		Y = 0.0f;
		std::cout << "Created Entity!" << std::endl;
	}
	~Entity()  //~后接类名声明/定义 析构函数
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}
	void Print()
	{
		std::cout << X << "," << Y << std::endl;
	}
};

void Funtion()
{
	Entity e;
	e.Print();
}
int main()
{
	Funtion();
	std::cin.get();
}