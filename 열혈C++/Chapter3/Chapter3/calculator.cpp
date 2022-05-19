#include <iostream>
#include <string>

using namespace std;

// ���� ����� ������ ����ü
class Calculator {
private:
	// �� ������ Ƚ���� ����
	int numOfAdd;
	int numOfDiv;
	int numOfMin;
	int numOfMul;

public:
	void Init();
	void ShowOpCount();

	// ����, ����, ����, ������
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
	cout << "����: " << numOfAdd << " ";
	cout << "����: " << numOfMin << " ";
	cout << "����: " << numOfMul << " ";
	cout << "������: " << numOfDiv << " ";

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


