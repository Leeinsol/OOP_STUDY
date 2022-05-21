#include <iostream>
using namespace std;
const int NAME_LEN = 20;

void ShowMenu();
void MakeAccount();
void DepositeMoney();
void WithdrawMoney();
void ShowAllAccInfo();

// ������
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

class Account
{
private:
	int accID;
	int balance;
	char *cusName;
public:
	// ������
	Account(int ID, int money, char* name)
		:accID(ID), balance(money)
	{
		cusName = new char[strlen(name) + 1];
		strcpy(cusName, name);
	}
	// ���������
	Account(const Account& ref)
		:accID(ref.accID), balance(ref.balance)
	{
		cusName = new char[strlen(ref.cusName) + 1];
		strcpy(cusName, ref.cusName);
	}

	// const ������ �Ͽ� ������ ����
	int GetAccID() const { return accID; }

	void Deposit(int money) {
		balance += money;
	}
	int Withdraw(int money) {
		if (balance < money)
			return 0;
		balance -= money;
		return money;
	}
	void showAccInfo() const {
		cout << "���� ID: " << accID << endl;
		cout << "�̸�: " << cusName << endl;
		cout << "�ܾ�: " << balance << endl;
	}
	~Account() {
		delete[]cusName;
	}
};

Account *accArr[100];
int accNum = 0;

int main() {
	int menu = 0;
	while (1) {
		ShowMenu();
		cout << "����: ";
		cin >> menu;
		cout << endl;

		switch (menu)
		{
		case MAKE:
			MakeAccount();
			break;
		case DEPOSIT:
			DepositeMoney();
			break;
		case WITHDRAW:
			WithdrawMoney();
			break;
		case INQUIRE:
			ShowAllAccInfo();
		case EXIT:
			for (int i = 0; i > accNum; i++)
				delete accArr[i];
			return 0;
		default:
			cout << "������ �� ���� �޴��Դϴ�. " << endl;
		}
	}
	return 0;
}

void ShowMenu() {
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

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

	accArr[accNum++] = new Account(id, balance, name);
}

void DepositeMoney() {
	int id = 0;
	int money = 0;

	cout << "[�Ա�]" << endl;
	cout << "���� ID: ";
	cin >> id;
	cout << "�Աݾ�: ";
	cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			accArr[i]->Deposit(money);
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
		cout << "��ȿ���� ���� ID �Դϴ�. " << endl << endl;
	}
}

void WithdrawMoney() {
	int id = 0;
	int money = 0;

	cout << "[���]" << endl;
	cout << "���� ID: ";
	cin >> id;
	cout << "��ݾ�: ";
	cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			if (accArr[i]->Withdraw(money) == 0) {
				cout << "�ܾ׺���" << endl << endl;
				return;
			}

			cout << "��ݿϷ�" << endl << endl;
			return;
		}
		cout << "��ȿ���� ���� ID �Դϴ�. " << endl << endl;
	}
}

void ShowAllAccInfo() {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->showAccInfo();
		cout << endl;
	}
}
