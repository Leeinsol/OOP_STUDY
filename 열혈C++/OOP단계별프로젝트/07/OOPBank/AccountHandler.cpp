#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"

AccountHandler::AccountHandler() :accNum(0) {

}

void AccountHandler::ShowMenu() const {
	cout << "-----Menu-----" << endl;
	cout << "1. ���°���" << endl;
	cout << "2. �Ա�" << endl;
	cout << "3. ���" << endl;
	cout << "4. �������� ��ü ���" << endl;
	cout << "5. ���α׷� ����" << endl;

	cout << "����: ";
}

void AccountHandler::MakeAccount(void) {
	int sel;

	cout << "[������������]" << endl;
	cout << "1. ���뿹�ݰ��� 2. �ſ�ŷڰ���" << endl;
	cout << "����: ";
	cin >> sel;

	if (sel == NORMAL)
		MakeNormalAccount();
	else
		MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount(void) {
	int id = 0;
	char name[NAME_LEN];
	int balance = 0;
	int InterRate = 0;

	cout << "[���뿹�ݰ��� ����]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�̸�: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> balance;
	cout << "������: ";
	cin >> InterRate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(id, balance, name, InterRate);
}

void AccountHandler::MakeCreditAccount(void)
{
	int id = 0;
	char name[NAME_LEN];
	int balance = 0;
	int InterRate = 0;
	int creditLevel;


	cout << "[�ſ�ŷڰ��� ����]" << endl;
	cout << "����ID: ";
	cin >> id;
	cout << "�̸�: ";
	cin >> name;
	cout << "�Աݾ�: ";
	cin >> balance;
	cout << "������: ";
	cin >> InterRate;
	cout << "�ſ���(1toA, 2toB, 3toC): ";
	cin >> creditLevel;
	cout << endl;

	switch (creditLevel)
	{
	case 1:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, InterRate, LEVEL_A);
		break;

	case 2:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, InterRate, LEVEL_B);
		break;

	case 3:
		accArr[accNum++] = new HighCreditAccount(id, balance, name, InterRate, LEVEL_C);
		break;

	default:
		break;
	}

}

void AccountHandler::DepositMoney(void) {
	int id;
	int money;

	cout << "[�Ա�]" << endl;

	cout << "����ID: ";
	cin >> id;
	cout << "�Աݾ�: ";
	cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			accArr[i]->Deposit(money);
			cout << "�ԱݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
}

void AccountHandler::WithdrawMoney(void) {
	int id;
	int money;

	cout << "[���]" << endl;

	cout << "����ID: ";
	cin >> id;
	cout << "��ݾ�: ";
	cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (id == accArr[i]->GetAccID()) {
			if (accArr[i]->Withdraw(money) == 0) {
				cout << "�ܾ׺���" << endl << endl;
				return;
			}
			cout << "��ݿϷ�" << endl << endl;
			return;
		}
	}
	cout << "��ȿ���� ���� ID �Դϴ�. " << endl << endl;
}

void AccountHandler::ShowAllAccInfo(void) const {
	for (int i = 0; i < accNum; i++) {
		accArr[i]->ShowAccInfo();
		cout << endl;
	}
}

AccountHandler::~AccountHandler() {
	for (int i = 0; i < accNum; i++) {
		delete[] accArr[i];
	}
}
