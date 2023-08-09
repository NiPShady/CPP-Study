#include<iostream>

class Log
{
private:
	Log(){}//通过设置构造函数为private来拒绝用户访问构造函数
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
	}
	Entity(float x,float y)//函数重载:相同函数名但有不同参数的不同函数版本
	{
		X = x;
		Y = y;
	}
	/*
	void Init()			//创建实例时初始化类中变量
	{
		X = 0.0f;
		Y = 0.0f;
	}
	*/
	void Print() 
	{
		std::cout << X << "," << Y << std::endl;
	}
};

int main() 
{	
	Entity e(10.00,2.00);
	//e.Init();
	e.Print();
	std::cin.get();
}