#pragma once
#ifndef __ACCOUNT_H__
#define __ACCOUNT_H__

class Account {
private:
	int accID;				//계좌번호
	int balance;			//잔액
	char* cusName;			//고객이름

public:
	Account(int ID, int money, char* name);
	Account(const Account &ref);
	Account& operator=(const Account& ref);		// 대입 연산자 오버로딩

	int GetAccID() const;
	virtual void Deposit(int money);
	int Withdraw(int money);
	void ShowAccInfo() const;

	~Account();
};

#endif // !__ACCOUNT_H__
