#include<iostream>

extern int s_Variable; //链接外部变量s_Variable

void Funtion()
{

}
int main()
{
	std::cout << s_Variable << std::endl;
	std::cin.get();
}
