#pragma once
#ifndef __ACCOUNT_HANDLER_H__
#define __ACCOUNT_HANDLER_H__

#include "Account.h"
#include "AccountArray.h"

class AccountHandler {
private:
	BoundCheckAccountPtrArray accArr;
	int accNum = 0;			//����� Account ��

public:
	AccountHandler();
	void ShowMenu(void) const;		//�޴����
	void MakeAccount(void);		//���°���
	void DepositMoney(void);	//�Ա�
	void WithdrawMoney(void);	//���
	void ShowAllAccInfo(void) const;	//�ܾ���ȸ
	~AccountHandler();

protected:
	void MakeNormalAccount(void);
	void MakeCreditAccount(void);

};

#endif // !__ACCOUNT_HANDLER_H__

