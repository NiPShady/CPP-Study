#include<iostream>
#include<string>
#include<array>

//����ֻ����־�Ͳ���ϵͳʹ��ģ��

template<typename T,int N>
class Array
{
private:
	T m_Array[N];
public:
	T GetSize() 
		const 
	{ 
		return N;
	}
};
//template��ʶ�ĺ���ֻ��һ��ģ��,��δ�����õ�����²���ʵ�ʴ���,���ᱻ����������
template<typename T> //templateģ��ؼ���,typename ģ�����������,Tģ�����������,������ģ�����(����)���滻������ģ���а�������������
void Print(T value) //T���滻��int
{
	std::cout << value << std::endl;
}

int main()
{
	Print<int>(5); //Print<typename> typenameʽ��Ҫʹ�ö�Ӧ��������ģ�庯������������
	Print("Hello World!");
	Print(5.5f);

	Array<int,5> array;
	std::cout << array.GetSize() << std::endl;

	std::cin.get();
}