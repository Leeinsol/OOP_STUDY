#include <iostream>

using namespace std;

int main() {
	int sell;

	while (1) {
		cout << "�Ǹ� �ݾ��� ���� ������ �Է�(-1 to end): ";
		cin >> sell;

		if (sell == -1)
			break;
		cout << "�̹� �� �޿�: " << 50 + sell * 0.12 << "����" << endl;

	}
	cout << "���α׷��� �����մϴ�. " << endl;
}
