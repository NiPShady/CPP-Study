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

		PrintEntity(this); //����ͨ��this�ؼ��ִ������ڲ��������⺯��
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
