#include <iostream>

using namespace std;

int main() {
	int sell;

	while (1) {
		cout << "판매 금액을 만원 단위로 입력(-1 to end): ";
		cin >> sell;

		if (sell == -1)
			break;
		cout << "이번 달 급여: " << 50 + sell * 0.12 << "만원" << endl;

	}
	cout << "프로그램을 종료합니다. " << endl;
}
