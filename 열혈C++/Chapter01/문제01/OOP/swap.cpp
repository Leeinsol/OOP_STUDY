#include <iostream>

using namespace std;

// 함수 오버로딩: 동일한 이름의 함수정의를 허용, 함수호출 시 전달되는 인자를 통해서 호출하고자 하는 함수를 구분 
// C++에서 함수 찾는 방법: 1. 함수의 이름, 2. 매개변수의 선언(자료형, 개수)
void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
	*b = temp;
}

void swap(char *a, char *b) {
	char temp = *a;
	*a = *b;
	*b = temp;
}

void swap(double *a, double *b) {
	double temp = *a;
	*a = *b;
	*b = temp;
}

int main() {
	int num1 = 20, num2 = 30;
	swap(&num1, &num2);
	cout << num1 << ' ' << num2 << endl;

	char ch1 = 'A', ch2 = 'Z';
	swap(&ch1, &ch2);
	cout << ch1 << ' ' << ch2 << endl;

	double dbl1 = 1.111, dbl2 = 5.555;
	swap(&dbl1, &dbl2);
	cout << dbl1 << ' ' << dbl2 << endl;

	return 0;
}
