#include <iostream>
using namespace std;

// ���� Ŭ����
class MyFriendInfo {
private:
	char* name;
	int age;
public:
	MyFriendInfo(const char*_name, int _age) :age(_age) {
		name = new char[strlen(_name) + 1];
		strcpy(name, _name);
	}
	void ShowMyFriendInfo() {
		cout << "�̸�: " << name << endl;
		cout << "����: " << age << endl;
	}
	~MyFriendInfo() {
		delete[]name;
	}
};

// ���� Ŭ����
class MyFriendDetailInfo :public MyFriendInfo {
private:
	char* addr;
	char* phone;
public:
	MyFriendDetailInfo(const char*_name, int _age, const char* _addr, const char* _phone)
		:MyFriendInfo(_name, _age)
	{
		addr = new char[strlen(_addr) + 1];
		strcpy(addr, _addr);
		phone = new char[strlen(_phone) + 1];
		strcpy(phone, _phone);
	}
	void ShowMyFriendDetailInfo() {
		ShowMyFriendInfo();
		cout << "�ּ�: " << addr << endl;
		cout << "��ȭ: " << phone << endl << endl;
	}
	~MyFriendDetailInfo() {
		delete[] addr;
		delete[] phone;
	}
};

int main() {
	MyFriendDetailInfo fren1("������", 22, "�泲 �ƻ�", "010-1234-5678");
	MyFriendDetailInfo fren2("���ּ�", 19, "��� ��õ", "010-1111-2222");
	fren1.ShowMyFriendDetailInfo();
	fren2.ShowMyFriendDetailInfo();

	return 0;
}

