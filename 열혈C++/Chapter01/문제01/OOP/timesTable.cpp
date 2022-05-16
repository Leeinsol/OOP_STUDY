#include <iostream>

using namespace std;

int main() {
	int num = 0;

	cout << "구구단 출력 프로그램" << endl;
	cout << "몇 단을 출력하시겠습니까? ";
	cin >> num;
	cout << endl;
	cout << num << "단 출력" << endl;

	for (int i = 1; i < 10; i++) {
		cout << num << "*" << i << "=" << num * i << endl;
	}
}
