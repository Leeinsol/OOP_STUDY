#include <iostream>
#include <cstdlib>
using namespace std;

class Point {
private:
	int xpos, ypos;
public:
	// ������
	Point(int x = 0, int y = 0) :xpos(x), ypos(y) {}
	friend ostream& operator<<(ostream& os, const Point& pos);
	friend ostream& operator<<(ostream& os, const Point* pos);

};

// ������ �����ε�
ostream& operator<<(ostream& os, const Point& pos) {
	os << '[' << pos.xpos << ". " << pos.ypos << ']' << endl;
	return os;
}
ostream& operator<<(ostream& os, const Point* pos) {
	os << '[' << pos->xpos << ". " << pos->ypos << ']' << endl;
	return os;

}

typedef Point * POINT_PTR;

class BoundCheckPontPtrArray
{
private:
	POINT_PTR *arr;
	int arrlen;

	BoundCheckPontPtrArray(const BoundCheckPontPtrArray& arr) {}
	BoundCheckPontPtrArray& operator=(const BoundCheckPontPtrArray& arr) {}
public:
	// ������
	BoundCheckPontPtrArray(int len) :arrlen(len)
	{
		arr = new POINT_PTR[len];
	}
	
	// ������ �����ε�
	POINT_PTR& operator[](int idx)
	{
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	POINT_PTR operator[](int idx) const
	{
		if (idx < 0 || idx >= arrlen) {
			cout << "Array index out of bound exception" << endl;
			exit(1);
		}
		return arr[idx];
	}
	int GetArrlen() const { return arrlen; }
	~BoundCheckPontPtrArray() { delete[]arr; }
};

int main() {
	BoundCheckPontPtrArray arr(3);
	arr[0] = new Point(3, 4);
	arr[1] = new Point(5, 6);
	arr[2] = new Point(7, 8);

	for (int i = 0; i < arr.GetArrlen(); i++)
		cout << arr[i];

	delete arr[0];
	delete arr[1];
	delete arr[2];

	return 0;
}
