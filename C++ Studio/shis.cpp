#include <iostream>
#include <string>

void PrintEntity(Entity* e);

class Entity
{
public:
	int x, y;

	Entity(int x, int y)
	{
		this->x = x;
		this->y = y;

		PrintEntity(this); //可以通过this关键字传递类内参数到类外函数
	}

	int Getx() const
	{
		const Entity* e = this;
		return e->x;
	}
 };

void PrintEntity(Entity *e)
{

}

int main()
{
	std::cin.get();
}
