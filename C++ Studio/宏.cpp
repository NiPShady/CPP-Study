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
	LOG("Hello World!") ; //ͨ���궨��ֻ��DEBUGģʽ���������
	WAIT; //������ʹ�ú� 
}