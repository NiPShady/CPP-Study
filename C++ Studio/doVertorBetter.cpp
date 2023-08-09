#include <iostream>
#include <string>
#include <vector>

struct Vertex
{
	float x, y, z;

	Vertex(float x, float y, float z)
		:x(x),y(y),z(z)
	{
	}

	Vertex(const Vertex& vertex)
		:x(vertex.x),y(vertex.y),z(vertex.z)
	{
		std::cout << "Copied!" << std::endl;
	}
};

int main()
{
	std::vector<Vertex> vertices;
	vertices.reserve(3); //设置Vertor容量
	vertices.emplace_back((1,2,3)); //emplace_back不传递vevtor对象,而是传递构造函数参数,不再占用内存复制,减少了内存的使用
	vertices.push_back(Vertex(4,5,6 ));
	vertices.push_back(Vertex(7,8,9));

	std::cin.get();
}