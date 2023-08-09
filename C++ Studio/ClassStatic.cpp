#include<iostream>

struct Entity
{
	int x, y;

	static void Print(Entity e) {//静态方法无法访问非静态变量
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
	e.Print(e);//正确调用应该为Entity::Print(e);
	Entity::Print(e1);
	std::cin.get();
}