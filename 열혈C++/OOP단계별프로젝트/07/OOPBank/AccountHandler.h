#pragma once
#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"

class AccountHandler {
private:
	Account* accArr[100];	//Accont 저장을 위한 배열
	int accNum = 0;			//저장된 Account 수

public:
	AccountHandler();
	void ShowMenu(void) const;		//메뉴출력
	void MakeAccount(void);		//계좌개설
	void DepositMoney(void);	//입금
	void WithdrawMoney(void);	//출금
	void ShowAllAccInfo(void) const;	//잔액조회
	~AccountHandler();

protected:
	void MakeNormalAccount(void);
	void MakeCreditAccount(void);

};

#endif // !__ACCOUNT_HANDLER_H__

