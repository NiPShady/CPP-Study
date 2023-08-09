#include<iostream>
#include<string>
#include<array>

//尽量只在日志和材质系统使用模板

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
//template标识的函数只是一个模板,在未被调用的情况下并不实际存在,不会被编译器编译
template<typename T> //template模板关键字,typename 模板参数的类型,T模板参数的名字,在整个模板代码(函数)中替换任意在模板中包含的数据类型
void Print(T value) //T被替换成int
{
	std::cout << value << std::endl;
}

int main()
{
	Print<int>(5); //Print<typename> typename式想要使用对应数据类型模板函数的数据类型
	Print("Hello World!");
	Print(5.5f);

	Array<int,5> array;
	std::cout << array.GetSize() << std::endl;

	std::cin.get();
}