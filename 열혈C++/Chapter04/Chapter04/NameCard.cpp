#include <iostream>
using namespace std;

namespace COMPANY
{
	//열거형
	enum { CLERK, SENIOR, ASSIST, MANAGER };

	void showPositionInfo(int pos) {
		switch (pos) {
		case CLERK:
			cout << "사원" << endl;
			break;
		case SENIOR:
			cout << "주임" << endl;
			break;
		case ASSIST:
			cout << "대리" << endl;
			break;
		case MANAGER:
			cout << "과장" << endl;
		}
	}
}

class NameCard {
private:
	char* name;
	char* company;
	char* phone;
	int position;
public:
	//생성자 함수
	NameCard(const char* _name, const char* _company, const char* _phone, int pos)
		:position(pos)
	{
		name = new char[strlen(_name) + 1];
		company = new char[strlen(_company) + 1];
		phone = new char[strlen(_phone) + 1];
		strcpy(name, _name);
		strcpy(company, _company);
		strcpy(phone, _phone);
	}
	void showNameCardInfo() {
		cout << "이름: " << name << endl;
		cout << "회사: " << company << endl;
		cout << "전화번호: " << phone << endl;
		cout << "직급: ";
		COMPANY::showPositionInfo(position);
		cout << endl;

	}
	~NameCard() {
		delete[]name;
		delete[]company;
		delete[]phone;
	}
};

int main() {
	NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMPANY::CLERK);
	NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMPANY::SENIOR);
	NameCard manAssist("Kim", "SoGoodComp", "010-5555-6666", COMPANY::ASSIST);
	manClerk.showNameCardInfo();
	manSENIOR.showNameCardInfo();
	manAssist.showNameCardInfo();

	return 0;
}


