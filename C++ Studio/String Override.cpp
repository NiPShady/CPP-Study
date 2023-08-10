#include <iostream>
#include <string>

class String
{
private:
	char* m_Buffer; //ָ���ַ�������
	unsigned int m_Size; //m_Size����string�Ĵ�С
public:
	String(const char* string)
	{
		m_Size = strlen(string); //�����ַ����ĳ���
		m_Buffer = new char[m_Size + 1]; //ʹ������(m_Buffer�����ַ���(string)�Ĵ�С+1)
		//���unsigned��int��������: https://blog.csdn.net/RiceVan/article/details/108336848
		memcpy(m_Buffer, string, m_Size);//��ָ�븴�Ƶ�ʵ�ʵĻ������� memcpy(Ŀ���ڴ�,������Դ�ڴ�,���ݴ�С)
		m_Buffer[m_Size] = 0;//�����ֹ��
	}

	//String(const String& other) //C++Ĭ���ṩ�Ŀ������캯��
	//	:m_Buffer(other.m_Buffer),m_Size(other.m_Size)
	//{

	//}

	//String(const String& other) = delete; //ͨ�����ÿ������캯������ֹǳ����

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

	char& operator[](unsigned int index) //[]����������
	{
		return m_Buffer[index];
	}

	friend std::ostream& operator<<(std::ostream& stream, const String& string);//friend�ؼ���->��Ԫʹ�ú������Է���˽�б���,����Ϊcout<<p
};

std::ostream& operator<<(std::ostream& stream, const String& string)
{
	stream << string.m_Buffer;
	return stream;
}

void PrintString(const String& string) //�������ñ����ظ�����,���ݲ���ʱ������ʹ��const����
{
	//String copy = string; //������Ҫcopy
	std::cout << string << std::endl;
}

int main()
{
	String string = "Cherno";
	String second = string; //ǳ�㿽��second��stringָ��ͬһ�����ڴ��ַ���������ظ��ͷ�ͬһ����ڴ汨��������

	second[2] = 'a'; //[]��Ҫ���в���������

	PrintString(string);
	PrintString(second);
	std::cin.get();
}