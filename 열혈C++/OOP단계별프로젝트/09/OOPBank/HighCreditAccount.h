#pragma once
#ifndef __HIGHCREIT_ACCOUNT_H__
#define __HIGHCREIT_ACCOUNT_H__

#include "NormalAccount.h"
#include "String.h"

class HighCreditAccount : public NormalAccount {
private:
	int specialRate;

public:
	HighCreditAccount(int ID, int money, String name, int rate, int special)
		:NormalAccount(ID, money, name, rate), specialRate(special)
	{

	}

	virtual void Deposit(int money) {
		NormalAccount::Deposit(money);	//���ݰ� �����߰�
		Account::Deposit(money*(specialRate / 100));	//Ư�� �����߰�
	}
};

#endif // !__HIGHCREIT_ACCOUNT_H__
