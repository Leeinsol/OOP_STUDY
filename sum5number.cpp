#include <iostream>

using namespace std;

int main() {
	int arr[5];
	int total = 0;

	for (int i = 0; i < 5; i++) {
		cout << i + 1 << "��° ���� �Է�: ";
		cin >> arr[i];
		total += arr[i];
	}

	cout << "�հ�: " << total << endl;
}
