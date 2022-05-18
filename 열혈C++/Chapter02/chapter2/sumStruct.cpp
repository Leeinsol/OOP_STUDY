#include <iostream>
using namespace std;

// 2차원 평면상에서의 좌표를 표시하는 구조체
typedef struct __Point {
	int xpos;
	int ypos;
}Point;

// 참조자를 이용한 구조체 더하기 연산
Point& PntAdder(const Point &p1, const Point &p2) {
	Point *pptr = new Point;
	pptr->xpos = p1.xpos + p2.xpos;
	pptr->ypos = p1.ypos + p2.ypos;
	return *pptr;
}

int main() {
	// 구조체 생성 및 변수 할당 
	Point *pptr1 = new Point;
	pptr1->xpos = 1;
	pptr1->ypos = 10;

	Point *pptr2 = new Point;
	pptr2->xpos = 2;
	pptr2->ypos = 20;

	Point &pref = PntAdder(*pptr1, *pptr2);
	cout << "[" << pref.xpos << ", " << pref.ypos << "]" << endl;


	// 변수 해제
	delete pptr1;
	delete pptr2;
	delete &pref;

	return 0;
}

