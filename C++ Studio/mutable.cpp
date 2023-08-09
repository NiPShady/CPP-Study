#include<iostream>
#include<string>

class Entity
{
private:
	std::string m_Name;
	mutable int m_DebugCount = 0; //统计GetName函数被调用的次数
public:
	const std::string& GetName() const 
	{
		m_DebugCount++;//mutable修饰词让函数被const限制时仍然可以改变被mutable修饰的变量值
		return m_Name;
	}
};

int main ()
{
	const Entity e;
	e.GetName();

	int x = 8;
	auto f = [=]() 	mutable  //lambda mutable使lambda可以改变值传递的变量
	{							
		x++;				 //int y = x; y++;
		std::cout << x << std::endl;
	};
	f();//x = 8;
	std::cin.get();
}