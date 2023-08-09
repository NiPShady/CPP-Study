#include<iostream>
#include<string>

class Entity
{
private:
	std::string m_Name;
	mutable int m_DebugCount = 0; //ͳ��GetName���������õĴ���
public:
	const std::string& GetName() const 
	{
		m_DebugCount++;//mutable���δ��ú�����const����ʱ��Ȼ���Ըı䱻mutable���εı���ֵ
		return m_Name;
	}
};

int main ()
{
	const Entity e;
	e.GetName();

	int x = 8;
	auto f = [=]() 	mutable  //lambda mutableʹlambda���Ըı�ֵ���ݵı���
	{							
		x++;				 //int y = x; y++;
		std::cout << x << std::endl;
	};
	f();//x = 8;
	std::cin.get();
}