#include<iostream>

struct Entity
{
	int x, y;

	static void Print(Entity e) {//��̬�����޷����ʷǾ�̬����
		std::cout<<"x=" << e.x << ",y=" << e.y << std::endl;
	}
};
int main() { 
	Entity e;
	e.x = 2;
	e.y = 3;

	Entity e1;
	e1.x = 5;
	e1.y = 8;
	e.Print(e);//��ȷ����Ӧ��ΪEntity::Print(e);
	Entity::Print(e1);
	std::cin.get();
}