#include<iostream>

class Entity
{
private:
	std::string m_Name;
	int m_Age;
public:
	Entity(const std::string& name)
		:m_Name(name),m_Age(-1){}
	Entity(int age)
		:m_Name("Unknow"), m_Age(age)
	{}
};

int main()
{
	std::cin.get();
}