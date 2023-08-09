#include<iostream>
#include<string>

class Entity
{
private:
	std::string m_Name;
public:
	Entity()
		:m_Name("UnKnown") //初始化列表 顺序与声明时一致
	{
	}
	Entity(const std::string& name)	
		:m_Name("Cherno")
	{
	}
	const std::string& GetName() const
	{
		return m_Name;
	}
};

int main() {
	Entity e;
	std::cout << e.GetName() << std::endl;
	Entity e1("Cherno");
	std::cout << e1.GetName() << std::endl;
	std::cin.get();
}