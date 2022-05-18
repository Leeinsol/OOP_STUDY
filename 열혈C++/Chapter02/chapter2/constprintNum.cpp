#include <iostream>
using namespace std;

// const 포인터와 cosnt 참조자
int main() {
	const int num = 12;
	const int *ptr = &num;
	const int *(&ref) = ptr;

	cout << *ptr << endl;
	cout << *ref << endl;

	return 0;
}


