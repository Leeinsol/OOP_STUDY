#include <iostream>
using namespace std;

// Square is a Rectangle -> ��Ӱ���
class Rectangle
{
private:
	int x;
	int y;

public:
	Rectangle(int a, int b)
		:x(a), y(b)
	{

	}
	void ShowAreaInfo() {
		cout << "����: " << x * y << endl;
	}
};

class Square :public Rectangle
{
public:
	Square(int a)
		:Rectangle(a, a)
	{

	}
};

int main() {
	Rectangle rec(4, 3);
	rec.ShowAreaInfo();

	Square sqr(7);
	sqr.ShowAreaInfo();
	return 0;
}

