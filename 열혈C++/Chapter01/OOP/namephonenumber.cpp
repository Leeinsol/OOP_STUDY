#include <iostream>

using namespace std;

int main() {
	char name[20];
	char phone[50];

	cout << "이름를 입력하세요: ";
	cin >> name;
	cout << "전화번호를 입력하세요: ";
	cin >> phone;

	cout << "-------------------------" << endl;
	cout << "이름: " << name << endl;
	cout << "전화번호: " << phone << endl;

}
