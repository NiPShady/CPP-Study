#include<iostream>
#include<string>

class Entity
{
private:
	std::string m_Name;
public:
	const std::string& GetName()const
	{
		return m_Name;
	}
};

int main() {
	std::cin.get();
}