#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

#include "String.h"

class Account {
private:
	int accID;				//°èÁÂ¹øÈ£
	int balance;			//ÀÜ¾×
	String cusName;			//°í°´ÀÌ¸§

public:
	Account(int ID, int money, String name);
	int GetAccID() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;
};

#endif // !__ACCOUNT_H__
