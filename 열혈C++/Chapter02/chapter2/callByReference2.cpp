#include <iostream>
using namespace std;


void SwapPointer(int *(&a), int *(&b)) {
	int *c = a;
	a = b;
	b = c;
}
int main() {
	int num1 = 5;
	int *ptr1 = &num1;
	int num2 = 10;
	int *ptr2 = &num2;

	cout << *ptr1 << endl;
	cout << *ptr2 << endl;

	SwapPointer(ptr1, ptr2);

	cout << *ptr1 << endl;
	cout << *ptr2 << endl;

	return 0;
}


