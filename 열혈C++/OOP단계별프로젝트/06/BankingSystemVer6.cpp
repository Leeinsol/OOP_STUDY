#include <iostream>
using namespace std;
const int NAME_LEN = 20;


//������
enum { MAKE = 1, DEPOSIT, WITHDRAW, INQUIRE, EXIT };

enum { LEVEL_A = 7, LEVEL_B = 4, LEVEL_C = 2 };

enum { NORMAL = 1, CREDIT = 2 };

// ���� Ŭ����
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
	virtual void Deposit(int money);
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

// ���� ���� ����
class NormalAccount :public Account
{
private:
	int InterRate;
public:
	NormalAccount(int ID, int money, char* name, int rate)
		:Account(ID, money, name), InterRate(rate)
	{

	}

	virtual void Deposit(int money) {
		Account::Deposit(money);
		Account::Deposit(money*(InterRate / 100.0));

	}
};

// �ſ� �ŷ� ����
class HighCredicAccount :public NormalAccount
{
private:
	int specialRate;
public:
	HighCredicAccount(int ID, int money, char* name, int rate, int special)
		:NormalAccount(ID, money, name, rate), specialRate(special)
	{}

	virtual void Deposit(int money) {
		NormalAccount::Deposit(money);
		Account::Deposit(money*(specialRate / 100.0));
	}
};


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
protected:
	void MakeNormalAccount();
	void MakeCreditAccount();
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
	int sel;
	cout << "[������������]" << endl;
	cout << "1. ���뿹�� ����";
	cout << "2. �ſ�ŷ� ����" << endl;
	cout << "����: ";
	cin >> sel;

	if (sel == NORMAL)
		MakeNormalAccount();
	else
		MakeCreditAccount();
}


void AccountHandler::MakeNormalAccount() {
	int id = 0;
	int balance = 0;
	char name[NAME_LEN];
	int interRate;

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "���� ID: ";
	cin >> id;
	cout << "�̸�: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> balance;
	cout << "������: ";
	cin >> interRate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(id, balance, name, interRate);

}

void AccountHandler::MakeCreditAccount() {
	int id = 0;
	int balance = 0;
	char name[NAME_LEN];
	int interRate;
	int creditLevel;

	cout << "[�ſ�ŷڰ��� ����]" << endl;
	cout << "���� ID: ";
	cin >> id;
	cout << "�̸�: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> balance;
	cout << "������: ";
	cin >> interRate;
	cout << "�ſ���(1toA, 2toB, 3toC)";
	cin >> creditLevel;
	cout << endl;

	switch (creditLevel) {
	case 1:
		accArr[accNum++] = new HighCredicAccount(id, balance, name, interRate, LEVEL_A);
		break;
	case 2:
		accArr[accNum++] = new HighCredicAccount(id, balance, name, interRate, LEVEL_B);
		break;
	case 3:
		accArr[accNum++] = new HighCredicAccount(id, balance, name, interRate, LEVEL_C);
		break;
	}
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


