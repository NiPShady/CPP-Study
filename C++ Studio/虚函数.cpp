#include<iostream>
//虚函数允许程序员在子类中重写方法
class Entity
{
public:
	virtual std::string GetName()//virtual 虚函数关键字
	{	
		return "Entity";	
	} 
};
class Player : public Entity
{
private:
	std::string m_Name;
public:
	Player(const std::string& name) : m_Name(name){}
	std::string GetName() override //override表示这是覆写的函数,增加代码可读性
	{  
		return m_Name;	
	}
};

void PrintName(Entity* entity)
{
	std::cout << entity->GetName() << std::endl;
}

int main()
{
	Entity* e = new Entity();
	PrintName(e);
	Player* player = new Player("Cherno");
	PrintName(player);
	std::cin.get();
}