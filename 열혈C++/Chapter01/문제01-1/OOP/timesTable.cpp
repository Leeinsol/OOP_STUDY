#include <iostream>

using namespace std;

int main() {
	int num = 0;

	cout << "������ ��� ���α׷�" << endl;
	cout << "�� ���� ����Ͻðڽ��ϱ�? ";
	cin >> num;
	cout << endl;
	cout << num << "�� ���" << endl;

	for (int i = 1; i < 10; i++) {
		cout << num << "*" << i << "=" << num * i << endl;
	}
}
