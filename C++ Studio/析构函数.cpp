#include<iostream>

class Log
{
private:
	//Log() {}//ͨ�����ù��캯��Ϊprivate���ܾ��û����ʹ��캯��
public:
	Log() = delete;//����Ĭ�Ϲ��캯��
};

class Entity {
public:
	float X, Y;

	Entity()//���캯��û�з��������к�����������������ͬ
	{
		X = 0.0f;
		Y = 0.0f;
		std::cout << "Created Entity!" << std::endl;
	}
	~Entity()  //~�����������/���� ��������
	{
		std::cout << "Destroyed Entity!" << std::endl;
	}
	void Print()
	{
		std::cout << X << "," << Y << std::endl;
	}
};

void Funtion()
{
	Entity e;
	e.Print();
}
int main()
{
	Funtion();
	std::cin.get();
}