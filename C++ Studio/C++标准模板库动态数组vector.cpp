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

void Funtion(const std::vector<Vertex>& vertices) //vertor传递参数时使用引用确保没有把整个数组复制到函数中
{

}

int main()
{
	std::vector<Vertex> vertices; // std::vertor<Class> variable 与Java不同的是vertor<Class>模板中的Class可以是基本类型如int 
	//Class使用类而不是指针时内存是连续的,在同一条高数缓存线上也利于遍历数组
	//而使用指针时因为存储的是地址,实际数据在内存中是分散的,修改空间大小时使用指针相对于使用类更快,增删查改时更推荐使用指针
	//尽量使用类型而不是指针
	vertices.push_back({ 1,2,3 }); //等价于Java中的.add)
	vertices.push_back({ 4,5,6 }); //.push_back({data1,data2,data3,...,datan});
	
	Funtion(vertices);

	for (int i = 0; i < vertices.size(); i++) //.size()获取vertor的大小长度
	{
		std::cout << vertices[i] << std::endl;
	}
	
	vertices.erase(vertices.begin()+1); //删除数组中某个元素.rease(vertices.begin()+n)
	
	//增强for循环相比上者代码更简洁
	for (const Vertex& v : vertices) //避免将每个vertex复制到这个for范围循环中使用引用
	{
		std::cout << v << std::endl;
	}

	vertices.clear(); //清除数组并大小设回0

	std::cin.get();
}