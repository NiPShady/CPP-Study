#include<iostream>

class Log
{
private:
	Log(){}//ͨ�����ù��캯��Ϊprivate���ܾ��û����ʹ��캯��
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
	}
	Entity(float x,float y)//��������:��ͬ���������в�ͬ�����Ĳ�ͬ�����汾
	{
		X = x;
		Y = y;
	}
	/*
	void Init()			//����ʵ��ʱ��ʼ�����б���
	{
		X = 0.0f;
		Y = 0.0f;
	}
	*/
	void Print() 
	{
		std::cout << X << "," << Y << std::endl;
	}
};

int main() 
{	
	Entity e(10.00,2.00);
	//e.Init();
	e.Print();
	std::cin.get();
}