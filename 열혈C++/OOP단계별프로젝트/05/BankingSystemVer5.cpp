#include <iostream>
using namespace std;
const int NAME_LEN = 20;

// ������
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

// Entity Ŭ����
// Ư¡: �������� ����, ���� �� ������ ���̽��� ����Ǵ� �����͸� ����
//		 ���α׷��� ����� �ľ��ϴµ� ������ ������ ���ϳ� ���α׷��󿡼� �����Ǵ� �������� ������ �ľ��ϴµ��� ������ ��
class Account
{
private:
	int accID;
	int balance;
	char *cusName;
public:
	Account(int ID, int money, char* name);
	Account(const Account& ref);
	int GetAccID() const;
	void Deposit(int money);
	int Withdraw(int money);
	void showAccInfo() const;
	~Account();

};

Account::Account(int ID, int money, char* name)
	:accID(ID), balance(money)
{
	cusName = new char[strlen(name) + 1];
	strcpy(cusName, name);
}
Account::Account(const Account& ref)
	: accID(ref.accID), balance(ref.balance)
{
	cusName = new char[strlen(ref.cusName) + 1];
	strcpy(cusName, ref.cusName);
}
int Account::GetAccID() const { return accID; }

void Account::Deposit(int money) {
	balance += money;
}
int Account::Withdraw(int money) {
	if (balance < money)
		return 0;
	balance -= money;
	return money;
}
void Account::showAccInfo() const {
	cout << "���� ID: " << accID << endl;
	cout << "�̸�: " << cusName << endl;
	cout << "�ܾ�: " << balance << endl;
}
Account::~Account() {
	delete[]cusName;
}

// ��Ʈ�� Ŭ����
// Ư¡: ���α׷� ��ü�� ����� ���, ����� ������ ���� Ŭ����, ���α׷��� ��ü ��ɰ� �帧 �ľ�
class AccountHandler
{
private:
	Account *accArr[100];
	int accNum;
public:
	AccountHandler();
	void ShowMenu() const;
	void MakeAccount();
	void DepositeMoney();
	void WithdrawMoney();
	void ShowAllAccInfo() const;
	~AccountHandler();

};

AccountHandler::AccountHandler() :accNum(0)
{}

void AccountHandler::ShowMenu() const {
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;
}

void AccountHandler::MakeAccount() {
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

void AccountHandler::DepositeMoney() {
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

void AccountHandler::WithdrawMoney() {
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

void AccountHandler::ShowAllAccInfo() const {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->showAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++) {
		delete[] accArr[i];
	}
}

int main() {
	AccountHandler manager;
	int menu = 0;
	while (1) {
		manager.ShowMenu();
		cout << "����: ";
		cin >> menu;
		cout << endl;

		switch (menu)
		{
		case MAKE:
			manager.MakeAccount();
			break;
		case DEPOSIT:
			manager.DepositeMoney();
			break;
		case WITHDRAW:
			manager.WithdrawMoney();
			break;
		case INQUIRE:
			manager.ShowAllAccInfo();
		case EXIT:
			return 0;
		default:
			cout << "������ �� ���� �޴��Դϴ�. " << endl;
		}
	}
	return 0;
}

