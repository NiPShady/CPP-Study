#include<iostream>
#include<string>

struct Vector2
{
	float x, y;

	Vector2(float x,float y)
		:x(x),y(y){}
	Vector2 Add(const Vector2& other) const //Ϊ�˱��⸴�ƽ��������Ϊconst
	{
		return Vector2(x + other.x, y + other.y);
	}
};
int main()
{
	Vector2 postition(4.0f, 4.0f);
	Vector2 speed(0.5f, 0.5f);

	Vector2 result = postition.Add(speed); //��ʹ�ò���������
	std::cin.get();
}