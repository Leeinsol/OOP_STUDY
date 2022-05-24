#include <iostream>
using namespace std;

// +=�����ڿ� -=������ �����ε�
// ����Լ� ������� �����ε�
// ������ ����� ���� ���� �� ������ pos1�� ��ü�� ��ȯ�ϵ��� ������ �����ε�

class Point {
private:
	int xpos, ypos;
public:
	Point(int x = 0, int y = 0) :xpos(x), ypos(y)
	{}
	void ShowPosition() const
	{
		cout << '[' << xpos << ", " << ypos << ']' << endl;
	}
	friend Point& operator--(Point &ref);
	friend Point operator~(const Point &ref);

	Point& operator++() {
		xpos += 1;
		ypos += 1;
		return *this;
	}

	Point operator-() {
		Point pos(-xpos, -ypos);
		return pos;
	}

};

Point& operator--(Point &ref) {
	ref.xpos -= 1;
	ref.ypos -= 1;
	return ref;
}

Point operator~(const Point &ref)
{
	Point pos(ref.ypos, ref.xpos);
	return pos;
}

int main() {
	Point pos1(9, -7);
	pos1.ShowPosition();
	Point pos2 = -pos1;
	pos2.ShowPosition();
	(~pos2).ShowPosition();
	pos2.ShowPosition();

	return 0;
}
