#include <iostream>
#include <string>

using namespace std;

// 계산기 기능을 가지는 구조체
class Calculator {
private:
	// 각 연산의 횟수를 저장
	int numOfAdd;
	int numOfDiv;
	int numOfMin;
	int numOfMul;

public:
	void Init();
	void ShowOpCount();

	// 덧셈, 뺄셈, 곱셈, 나눗셈
	double Add(double x, double y);
	double Div(double x, double y);
	double Min(double x, double y);
	double Mul(double x, double y);
};

void Calculator::Init() {
	numOfAdd = 0;
	numOfDiv = 0;
	numOfMin = 0;
	numOfMul = 0;
}

void Calculator::ShowOpCount() {
	cout << "덧셈: " << numOfAdd << " ";
	cout << "뺄셈: " << numOfMin << " ";
	cout << "곱셈: " << numOfMul << " ";
	cout << "나눗셈: " << numOfDiv << " ";

}

double Calculator::Add(double x, double y) {
	numOfAdd++;
	return x + y;
}

double Calculator::Div(double x, double y) {
	numOfDiv++;
	return x / y;
}

double Calculator::Min(double x, double y) {
	numOfMin++;
	return x - y;
}

double Calculator::Mul(double x, double y) {
	numOfMul++;
	return x * y;
}

int main() {
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << endl;
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << endl;
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << endl;
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << endl;
	cal.ShowOpCount();

	return 0;
}


