#include <iostream>
using namespace std;

// ���� ����ü
typedef struct {
	int accID;
	int balance;
	char cusName[20];
}Account;

Account accArr[100];
int accNum = 0;

void ShowMenu() {
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

// ���� �輳
void MakeAccount() {
	int id = 0;
	int balance = 0;
	char name[20];

	cout << "[���°���]" << endl;
	cout << "���� ID: ";
	cin >> id;
	cout << "�̸�: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> balance;
	cout << endl;

	accArr[accNum].accID = id;
	accArr[accNum].balance = balance;
	strcpy(accArr[accNum].cusName, name);
	accNum++;
}

// �Ա�
void DepositeMoney() {
	int id = 0;
	int money = 0;

	cout << "[�Ա�]" << endl;
	cout << "���� ID: ";
	cin >> id;
	cout << "�Աݾ�: ";
	cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			accArr[i].balance += money;
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
		cout << "��ȿ���� ���� ID �Դϴ�. " << endl << endl;
	}
}

//���
void WithdrawMoney() {
	int id = 0;
	int money = 0;

	cout << "[���]" << endl;
	cout << "���� ID: ";
	cin >> id;
	cout << "��ݾ�: ";
	cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i].accID == id) {
			if (accArr[i].balance < money) { //��ݾ��� �ܾ׺��� Ŭ ��
				cout << "�ܾ׺���" << endl << endl;
			}
			accArr[i].balance -= money;
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
		cout << "��ȿ���� ���� ID �Դϴ�. " << endl << endl;
	}
}

void ShowAllAccInfo() {
	for (int i = 0; i < accNum; i++) {
		cout << "���� ID: " << accArr[i].accID << endl;
		cout << "�̸�: " << accArr[i].cusName << endl;
		cout << "�ܾ�: " << accArr[i].balance << endl << endl;
	}
}

int main() {
	int menu = 0;
	while (1) {
		ShowMenu();
		cout << "����: ";
		cin >> menu;
		cout << endl;

		switch (menu)
		{
		case 1:
			MakeAccount();
			break;
		case 2:
			DepositeMoney();
			break;
		case 3:
			WithdrawMoney();
			break;
		case 4:
			ShowAllAccInfo();
		case 5:
			return 0;
		default:
			cout << "������ �� ���� �޴��Դϴ�. " << endl;
		}
	}
	return 0;
}


