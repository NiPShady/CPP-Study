#include<iostream>
#include<string>

class Entity
{
private:
	int m_X, *m_Y;
	mutable int var; //mutable�������ǳ�������,�������޸�mutable���εı���
public:
	int GetX() const  //const�޶����ú��������޸���,ֻ��
	{
		m_X = 2;
		var = 2;
		return m_X;
	}
	const int* const GetY() const//ֻ����������һ�����ܱ��޸ĵ�ָ��
	{
		return m_Y;
	}
	int SetX(int x) 
	{
		m_X = x;
	}
};

void PrintEntity(const Entity& e) //ͨ���������ô��ݲ��Ḵ��ԭ��
{
	e = Entity(); //���ó�ʼ���󲻿ɸ���
	std::cout<<e.GetX()<<std::endl;//�ں����������ೣ������ʱֻ�ܵ�������const�汾����
}

int main() {

	Entity e;

	const int MAX_AGE = 90; //���岻�ɸ��ĵĳ���ֵ
	MAX_AGE = 0;
	const int* a = new int;//����const����һ�����ɸı�ָ���ڴ��ֵ���ɸı�ָ���ָ��
	*a = MAX_AGE;
	a = (int*)&MAX_AGE;
	int* const a1 = new int;//�ײ�const����һ���ɸı�ָ���ڴ��ֵ�����ɸı�ָ���ָ��
	*a1 = MAX_AGE;
	a1 = (int*)&MAX_AGE;
	const int* const a2 = new int;// ����һ�����ɸı�ָ���ڴ��ֵҲ���ɸı�ָ���ָ��
	*a2 = MAX_AGE;
	a2 = (int*)&MAX_AGE;
}