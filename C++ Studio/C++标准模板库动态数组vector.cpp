#include <iostream>
#include <string>
#include<vector>

struct Vertex
{
	float x, y, z;
};

std::ostream& operator<<(std::ostream& stream, const Vertex& vertex)
{
	stream << vertex.x << "," << vertex.y << "," << vertex.z;
	return stream;
}

void Funtion(const std::vector<Vertex>& vertices) //vertor���ݲ���ʱʹ������ȷ��û�а��������鸴�Ƶ�������
{

}

int main()
{
	std::vector<Vertex> vertices; // std::vertor<Class> variable ��Java��ͬ����vertor<Class>ģ���е�Class�����ǻ���������int 
	//Classʹ���������ָ��ʱ�ڴ���������,��ͬһ��������������Ҳ���ڱ�������
	//��ʹ��ָ��ʱ��Ϊ�洢���ǵ�ַ,ʵ���������ڴ����Ƿ�ɢ��,�޸Ŀռ��Сʱʹ��ָ�������ʹ�������,��ɾ���ʱ���Ƽ�ʹ��ָ��
	//����ʹ�����Ͷ�����ָ��
	vertices.push_back({ 1,2,3 }); //�ȼ���Java�е�.add)
	vertices.push_back({ 4,5,6 }); //.push_back({data1,data2,data3,...,datan});
	
	Funtion(vertices);

	for (int i = 0; i < vertices.size(); i++) //.size()��ȡvertor�Ĵ�С����
	{
		std::cout << vertices[i] << std::endl;
	}
	
	vertices.erase(vertices.begin()+1); //ɾ��������ĳ��Ԫ��.rease(vertices.begin()+n)
	
	//��ǿforѭ��������ߴ�������
	for (const Vertex& v : vertices) //���⽫ÿ��vertex���Ƶ����for��Χѭ����ʹ������
	{
		std::cout << v << std::endl;
	}

	vertices.clear(); //������鲢��С���0

	std::cin.get();
}