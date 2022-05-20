#include <iostream>
using namespace std;

class Point {
private:
	int xpos;
	int ypos;

public:
	//생성자
	Point(int x, int y) :xpos(x), ypos(y) {

	}

	//초기화 함수
	void Init(int x, int y) {
		xpos = x;
		ypos = y;
	}
	void ShowPointInfo() const {
		cout << "[" << xpos << ", " << ypos << "]" << endl;
	}
};

//Point 클래스를 기반으로 하는 Circle 클래스
class Circle {
private:
	int rad;
	Point center;

public:
	//생성자
	Circle(int x, int y, int r) :center(x, y) {
		rad = r;
	}

	//초기화 함수
	void Init(int x, int y, int r) {
		rad = r;
		center.Init(x, y);
	}

	void ShowCircleInfo() const {
		cout << "radius: " << rad << endl;
		center.ShowPointInfo();
	}
};

class Ring {
private:
	Circle inCircle;
	Circle outCircle;

public:
	//생성자
	Ring(int inX, int inY, int inR, int outX, int outY, int outR)
		:inCircle(inX, inY, inR), outCircle(outX, outY, outR)
	{

	}

	//초기화 함수
	void Init(int inX, int inY, int inR, int outX, int outY, int outR) {
		inCircle.Init(inX, inY, inR);
		outCircle.Init(outX, outY, outR);
	}
	void ShowRingInfo() const
	{
		cout << "Inner Circle Info..." << endl;
		inCircle.ShowCircleInfo();
		cout << "Outter Circle Info..." << endl;
		outCircle.ShowCircleInfo();
	}
};


int main() {
	Ring ring(1, 1, 4, 2, 2, 9);	//생성자 사용
	//ring.Init(1, 1, 4, 2, 2, 9);	//초기화 함수 사용
	ring.ShowRingInfo();

	return 0;
}


