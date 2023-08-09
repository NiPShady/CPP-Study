#include <iostream>
#include <string>

class String
{
private:
	char* m_Buffer; //指向字符缓冲区
	unsigned int m_Size; //m_Size保存string的大小
public:
	String(const char* string)
	{
		m_Size = strlen(string); //计算字符串的长度
		m_Buffer = new char[m_Size + 1]; //使缓冲区(m_Buffer等于字符串(string)的大小+1)
		//解决unsigned与int计算问题: https://blog.csdn.net/RiceVan/article/details/108336848
		memcpy(m_Buffer, string, m_Size);//将指针复制到实际的缓冲区中 memcpy(目标内存,数据来源内存,数据大小)
		m_Buffer[m_Size] = 0;//添加终止符
	}

	//String(const String& other) //C++默认提供的拷贝构造函数
	//	:m_Buffer(other.m_Buffer),m_Size(other.m_Size)
	//{

	//}

	//String(const String& other) = delete; //通过禁用拷贝构造函数来禁止浅拷贝

	String(const String& other)
		:m_Size(other.m_Size)
	{
		std::cout << "Copy String !";

		m_Buffer = new char[m_Size + 1];
		memcpy(m_Buffer, other.m_Buffer, m_Size + 1);
	}

	~String()
	{
		delete[] m_Buffer;
	}

	char& operator[](unsigned int index) //[]操作符重载
	{
		return m_Buffer[index];
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);//friend关键字->友元使得函数可以访问私有变量,本质为cout<<p
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}

void PrintString(const String& string) //传递引用避免重复复制,传递参数时尽可能使用const引用
{
	//String copy = string; //加入需要copy
	std::cout << string << std::endl;
}

int main()
{
	String string = "Cherno";
	String second = string; //浅层拷贝second和string指向同一个堆内存地址析构函数重复释放同一块堆内存报错程序崩溃

	second[2] = 'a'; //[]需要进行操作符重载

	PrintString(string);
	PrintString(second);
	std::cin.get();
}