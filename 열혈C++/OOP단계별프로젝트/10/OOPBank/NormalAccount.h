#pragma once
#ifndef __NORMAL_ACCOUNT_H__
#define __NORMAL_ACCOUNT_H__

#include "Account.h"
#include "String.h"

class NormalAccount : public Account {
private:
	int InterRate;	//������ %����
public:
	NormalAccount(int ID, int money, String name, int rate)
		:Account(ID, money, name), InterRate(rate)
	{

	}

	virtual void Deposit(int money) {
		Account::Deposit(money);	//���� �߰�
		Account::Deposit(money*(InterRate / 100));	//�����߰�
	}
};

#endif // !__NORMAL_ACCOUNT_H__
