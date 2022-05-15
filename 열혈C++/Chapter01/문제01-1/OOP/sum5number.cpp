#include <iostream>

using namespace std;

int main() {
	int arr[5];
	int total = 0;

	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "번째 정수 입력: ";
		cin >> arr[i];
		total += arr[i];
	}

	cout << "합계: " << total << endl;
}
