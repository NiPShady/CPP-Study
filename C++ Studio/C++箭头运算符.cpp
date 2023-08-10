#include <iostream>
#include <string>

class Entity
{
public:
	int x;

	void Print()
		const //const��ǵ�������������õĺ���Ҳ��Ҫ���const
	{
		std::cout << "Hello !" << std::endl;
	}
};

class ScopedPtr
{
private:
	Entity* m_Obj;
public:
	ScopedPtr(Entity* entity)
	{
	}

	~ScopedPtr()
	{
		delete m_Obj;
	}

	Entity* operator->() //����'->'��ͷ�����ʹ��ScopedPtr����Է���Entity��
	{
		return m_Obj;
	}

	const Entity* operator->() //����'->'��ͷ�����ʹ��ScopedPtr����Է���Entity��
		const  //const��ǵı���ʹ��'->'���ص�const�汾,ʹ��const�汾ʱ,���õĺ���Ҳ��Ҫ���Ϊconst
	{
		return m_Obj;
	}
};

struct Vector3
{
	float x, y, z;
};

int main()
{
	//Entity e; 
	//e.Print();

	//Entity* ptr = &e;

	//ptr->x = 2;
	//ptr->Print();
	//

	const ScopedPtr entity = new Entity(); //��entity(Class:Entity)������Χʱ,ScopedPtr�Զ�����entity(Class:Entity)
	entity->Print();//����'->'��ͷ������

	/*ͨ����ͷ��������ȡ�ڴ���ĳ��������ƫ����*/
	
	//��ַ��0��ʼ
	//���Ƚ�nullptrǿ��ת��ΪVevtor3ָ��
	//Ȼ���ü�ͷ���Ʒ�����x,�õ��ڴ�Ĳ���
	//ȡx���ڴ��ַ�õ�x��ƫ����
	//���ת��Ϊint��ֵ��offset�洢x���ڴ��е�ƫ����
	int offset = (int)&((Vector3*)nullptr)->x; //offset�洢x��ƫ����
	std::cout << offset << std::endl;

	std::cin.get();
}