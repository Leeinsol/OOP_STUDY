#include <iostream>
using namespace std;

// Car 클래스
class Car {
private:
	int gasolineGauge;
public:
	Car(int gas)
		:gasolineGauge(gas)
	{

	}

	int GetGasGauge() {
		return gasolineGauge;
	}
};

// Car 클래스를 상속받는 HybridCar 클래스
class HybridCar :public Car {
private:
	int electricGauge;
public:
	// 생성자
	HybridCar(int gas, int elec)
		:Car(gas), electricGauge(elec)
	{

	}
	int GetElecGauge() {
		return electricGauge;
	}
};

// HybridCar 클래스를 상속받는 HybridWaterCar 클래스
class HybridWaterCar :public HybridCar {
private:
	int waterGauge;
public:
	// 생성자
	HybridWaterCar(int gas, int elec, int water)
		:HybridCar(gas, elec), waterGauge(water)
	{

	}
	void ShowCurrentGauge() {
		cout << "잔여 가솔린: " << GetGasGauge() << endl;
		cout << "잔여 전기량: " << GetElecGauge() << endl;
		cout << "잔여 워터량: " << waterGauge << endl;
	}
};

int main() {
	HybridWaterCar hybridwatercar(50, 40, 30);
	hybridwatercar.ShowCurrentGauge();
	return 0;
}

