#include <iostream>
class Car {
public:
	void foo() {
		std::cout << "i,ts Car" << std::endl;
	}
};
class Van : public Car{
public:
	void foo() {
		std::cout << "i,ts Van" << std::endl;
	}
};
int main() {
	
	int j;
	double i = 32200030001.1;
	j = static_cast<int>(i);//��������� �������� ���� double �� ���� int 
	//static_cast ����� ���� ������ �������� ������������� �����, �� ��� ��� �������� ���� 
	//���� ��������� ��� �������� ��������� �������� ��������� ��� 
	std::cout << j << std::endl;
	
	std::cout << "********************" << std::endl;
	double  a = 3.41;
	const double *pC = &a;
	double* ppC = const_cast<double*>(pC);
	std::cout << typeid(* ppC).name() << std::endl;

	std::cout << "********************" << std::endl;
	//Van* pVan = (Van*)pcar �� ������� ���� ���� �� ��������� ��������
	Car car;
	Van van;
	Car* pcar = &van;//upcast Van to Car
	Van* pVan = (Van*)pcar;//downcast Car to Van
	//Van* pVan = dynamic_cast<Van*>(&pcar) �� ������� ���� ���� � ���������� �� ������������ ������������
	//downcast UB
	//Van* pvan = (Van*)&pcar;�������� �� ������ ������� ��������� �� ��������
	return 0;
};
