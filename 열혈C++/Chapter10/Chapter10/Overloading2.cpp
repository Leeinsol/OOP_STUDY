#include <iostream>
using namespace std;

// +=연산자와 -=연산자 오버로딩
// 멤버함수 기반으로 오버로딩
// 연산의 결과로 값이 증가 및 감소한 pos1의 객체를 반환하도록 연산자 오버로딩

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
