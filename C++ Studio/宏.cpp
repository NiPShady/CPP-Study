#include<iostream>
#include<string>

#define PR_DEBUG 0  

#ifdef PR_DEBUG == 1

#define WAIT std::cin.get()
#define LOG(x) std::cout << x << std::endl;

#else
#define LOG(x)
#endif

int main()
{
	LOG("Hello World!") ; //通过宏定义只在DEBUG模式下启用语句
	WAIT; //尽量少使用宏 
}