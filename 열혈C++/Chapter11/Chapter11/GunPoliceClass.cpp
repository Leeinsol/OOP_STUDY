#include <iostream>
#include <cstring>
using namespace std;

class Gun {
private:
	int bullet;
public:
	Gun(int bnum) :bullet(bnum)
	{}
	void Shot() {
		cout << "BBANG!" << endl;
		bullet--;
	}
};

class Police
{
private:
	int handcuffs;	// 소유한 수갑의 수
	Gun * pistol;	// 소유하고 있는 권총
public:
	// 생성자
	Police(int bnum, int bcuff)
		:handcuffs(bcuff)
	{
		if (bnum > 0)
			pistol = new Gun(bnum);
		else
			pistol = NULL;
	}

	// 복사 생성자
	Police(const Police& ref)
		:handcuffs(ref.handcuffs)
	{
		if (ref.pistol != NULL)
			pistol = new Gun(*(ref.pistol));
		else
			pistol = NULL;
	}

	// 대입 연산자 오버로딩
	Police& operator=(const Police& ref) {
		if (pistol != NULL)
			delete pistol;
		if (ref.pistol != NULL)
			pistol = new Gun(*(ref.pistol));
		else
			pistol = NULL;

		handcuffs = ref.handcuffs;
		return *this;
	}

	void PutHandcuff() {
		cout << "SNAP!" << endl;
		handcuffs--;
	}

	void Shot() {
		if (pistol == NULL)
			cout << "Hut BBANG!" << endl;
		else
			pistol->Shot();
	}

	~Police()
	{
		if (pistol != NULL)
			delete pistol;
	}
};

int main() {
	Police pman1(5, 3);
	Police pman2 = pman1;
	pman2.PutHandcuff();
	pman2.Shot();

	Police pman3(2, 4);
	pman3 = pman1;
	pman3.PutHandcuff();
	pman3.Shot();

	return 0;
}
