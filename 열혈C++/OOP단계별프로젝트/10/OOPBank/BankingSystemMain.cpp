#include "BankingCommonDecl.h"
#include "AccountHandler.h"

int main(void) {
	AccountHandler manager;
	int choice = 0;

	while (1) {
		manager.ShowMenu();
		cout << "����: ";
		cin >> choice;
		cout << endl;

		switch (choice)
		{
		case MAKE:
			manager.MakeAccount();
			break;

		case DEPOSIT:
			manager.DepositMoney();
			break;

		case WITHDRAW:
			manager.WithdrawMoney();
			break;

		case INQUIRE:
			manager.ShowAllAccInfo();
			break;
		case EXIT:
			return 0;

		default:
			cout << "�޴��� �����ϼ���. " << endl << endl;
			break;
		}
	}
	return 0;

}

