#include<iostream>
#include<string>

int main()
{
	auto a = 5; //auto关键字让编译器自动识别5为int,并将auto关键字自动替换成int

	auto b = a; //auto关键字让编译器自动识别a的数据类型为int,将auto关键字替换为int,此时auto b 完全等价为int b 

	std::cin.get();
}