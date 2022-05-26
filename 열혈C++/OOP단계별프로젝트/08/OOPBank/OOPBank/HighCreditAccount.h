#pragma once
#ifndef __HIGHCREIT_ACCOUNT_H__
#define __HIGHCREIT_ACCOUNT_H__

#include "NormalAccount.h"

class HighCreditAccount : public NormalAccount {
private:
	int specialRate;

public:
	HighCreditAccount(int ID, int money, char* name, int rate, int special)
		:NormalAccount(ID, money, name, rate), specialRate(special)
	{

	}

	virtual void Deposit(int money) {
		NormalAccount::Deposit(money);	//원금과 이자추가
		Account::Deposit(money*(specialRate / 100));	//특별 이자추가
	}
};

#endif // !__HIGHCREIT_ACCOUNT_H__
