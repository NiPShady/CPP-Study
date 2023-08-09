#include<iostream>
#include<string>

class Entity
{
private:
	int m_X, *m_Y;
	mutable int var; //mutable允许函数是常量方法,但可以修改mutable修饰的变量
public:
	int GetX() const  //const限定词让函数不能修改类,只读
	{
		m_X = 2;
		var = 2;
		return m_X;
	}
	const int* const GetY() const//只读函数返回一个不能被修改的指针
	{
		return m_Y;
	}
	int SetX(int x) 
	{
		m_X = x;
	}
};

void PrintEntity(const Entity& e) //通过常量引用传递不会复制原参
{
	e = Entity(); //引用初始化后不可更改
	std::cout<<e.GetX()<<std::endl;//在函数参数有类常量引用时只能调用类中const版本函数
}

int main() {

	Entity e;

	const int MAX_AGE = 90; //定义不可更改的常量值
	MAX_AGE = 0;
	const int* a = new int;//顶层const定义一个不可改变指向内存的值但可改变指向的指针
	*a = MAX_AGE;
	a = (int*)&MAX_AGE;
	int* const a1 = new int;//底层const定义一个可改变指向内存的值但不可改变指向的指针
	*a1 = MAX_AGE;
	a1 = (int*)&MAX_AGE;
	const int* const a2 = new int;// 定义一个不可改变指向内存的值也不可改变指向的指针
	*a2 = MAX_AGE;
	a2 = (int*)&MAX_AGE;
}