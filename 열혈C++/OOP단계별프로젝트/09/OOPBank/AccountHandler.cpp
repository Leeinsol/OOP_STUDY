#include "BankingCommonDecl.h"
#include "AccountHandler.h"
#include "Account.h"
#include "NormalAccount.h"
#include "HighCreditAccount.h"
#include "String.h"

AccountHandler::AccountHandler() :accNum(0) {

}

void AccountHandler::ShowMenu() const {
	cout << "-----Menu-----" << endl;
	cout << "1. 계좌개설" << endl;
	cout << "2. 입금" << endl;
	cout << "3. 출금" << endl;
	cout << "4. 계좌정보 전체 출력" << endl;
	cout << "5. 프로그램 종료" << endl;

	cout << "선택: ";
}

void AccountHandler::MakeAccount(void) {
	int sel;

	cout << "[계좌종류선택]" << endl;
	cout << "1. 보통예금계좌 2. 신용신뢰계좌" << endl;
	cout << "선택: ";
	cin >> sel;

	if (sel == NORMAL)
		MakeNormalAccount();
	else
		MakeCreditAccount();
}

void AccountHandler::MakeNormalAccount(void) {
	int id = 0;
	String name;
	int balance = 0;
	int InterRate = 0;

	cout << "[보통예금계좌 개설]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "이름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> balance;
	cout << "이자율: ";
	cin >> InterRate;
	cout << endl;

	accArr[accNum++] = new NormalAccount(id, balance, name, InterRate);
}

void AccountHandler::MakeCreditAccount(void)
{
	int id = 0;
	String name;
	int balance = 0;
	int InterRate = 0;
	int creditLevel;


	cout << "[신용신뢰계좌 개설]" << endl;
	cout << "계좌ID: ";
	cin >> id;
	cout << "이름: ";
	cin >> name;
	cout << "입금액: ";
	cin >> balance;
	cout << "이자율: ";
	cin >> InterRate;
	cout << "신용등급(1toA, 2toB, 3toC): ";
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

	cout << "[입금]" << endl;

	cout << "계좌ID: ";
	cin >> id;
	cout << "입금액: ";
	cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (accArr[i]->GetAccID() == id) {
			accArr[i]->Deposit(money);
			cout << "입금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다." << endl << endl;
}

void AccountHandler::WithdrawMoney(void) {
	int id;
	int money;

	cout << "[출금]" << endl;

	cout << "계좌ID: ";
	cin >> id;
	cout << "출금액: ";
	cin >> money;

	for (int i = 0; i < accNum; i++) {
		if (id == accArr[i]->GetAccID()) {
			if (accArr[i]->Withdraw(money) == 0) {
				cout << "잔액부족" << endl << endl;
				return;
			}
			cout << "출금완료" << endl << endl;
			return;
		}
	}
	cout << "유효하지 않은 ID 입니다. " << endl << endl;
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
