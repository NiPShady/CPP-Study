#include<iostream>
//�麯���������Ա����������д����
class Entity
{
public:
	virtual std::string GetName()//virtual �麯���ؼ���
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
	std::string GetName() override //override��ʾ���Ǹ�д�ĺ���,���Ӵ���ɶ���
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