#include <iostream>
using namespace std;

// �����ڸ� �̿���  Call by Reference 
void IncreaseNum(int &num) {
	num++;
}

void changeNum(int &num) {
	num *= -1;
}

int main() {
	int number = 10;
	IncreaseNum(number);
	cout << number << endl;

	changeNum(number);
	cout << number << endl;

	return 0;
}


