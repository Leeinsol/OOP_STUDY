#include <iostream>
using namespace std;

// Car Ŭ����
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

// Car Ŭ������ ��ӹ޴� HybridCar Ŭ����
class HybridCar :public Car {
private:
	int electricGauge;
public:
	// ������
	HybridCar(int gas, int elec)
		:Car(gas), electricGauge(elec)
	{

	}
	int GetElecGauge() {
		return electricGauge;
	}
};

// HybridCar Ŭ������ ��ӹ޴� HybridWaterCar Ŭ����
class HybridWaterCar :public HybridCar {
private:
	int waterGauge;
public:
	// ������
	HybridWaterCar(int gas, int elec, int water)
		:HybridCar(gas, elec), waterGauge(water)
	{

	}
	void ShowCurrentGauge() {
		cout << "�ܿ� ���ָ�: " << GetGasGauge() << endl;
		cout << "�ܿ� ���ⷮ: " << GetElecGauge() << endl;
		cout << "�ܿ� ���ͷ�: " << waterGauge << endl;
	}
};

int main() {
	HybridWaterCar hybridwatercar(50, 40, 30);
	hybridwatercar.ShowCurrentGauge();
	return 0;
}

