#include <iostream>

class Entity
{
public:
	float X, Y;
	void Move(float xa, float ya)
	{
		X += xa;
		Y += ya;
	}
};

class Player   //继承格式 class 子类 : public 父类
{
public:
	const char* Name;

	void PrintName()
	{
		std::cout << Name << std::endl;
	}
};

int main() {
	std::cout << sizeof(Player) << std::endl;
	//Player player;
	//player.PrintName();
	//player.Move(5,5);
	//player.X = 2;
	std::cin.get();
}