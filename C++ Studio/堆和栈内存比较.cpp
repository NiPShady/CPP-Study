//堆和栈实际位置都在内存中
#include<iostream>
#include<string>

struct Vector3
{
	float x, y, z;

	Vector3()
		:x(10),y(11),z(12)
	{

	}
};

int main()
{
	//栈分配内存
	int value = 5;
	int array[5] = {1,2,3,4,5};
	Vector3 vector;

	//堆分配内存
	int* hvalue = new int;
	*hvalue = 5;
	int* harray = new int[5];
	for (int i = 0; i < 5; i++)
	{
		*harray = i+1;
	}
	Vector3 *hvector = new Vector3();

	//std::cout << sizeof(value) << sizeof(*hvalue) <<  std::endl;

	delete hvalue;
	delete[] harray;
	delete hvector;

	std::cin.get();
}