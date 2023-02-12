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
	setlocale(LC_ALL, "russian");
	int j;
	double i = 32200030001.1;
	j = static_cast<int>(i);//произошло урезание типа double до типа int 
	//static_cast перед этим провел проверку совместимости типов, но так как диапазон дабл 
	//выше диапазона инт вывелось последнее значение диапазона инт 
	std::cout << j << std::endl;
	
	std::cout << "********************" << std::endl;
	double  a = 3.41;
	const double *pC = &a;
	double* ppC = const_cast<double*>(pC);
	std::cout << typeid(* ppC).name() << std::endl;

	std::cout << "********************" << std::endl;
	//Van* pVan = (Van*)pcar не удачный даун каст до появления обьектов
	Car car;
	Van van;
	Car* pcar = &van;//upcast Van to Car
	Van* pVan = (Van*)pcar;//downcast Car to Van
	//Van* pVan = dynamic_cast<Van*>(&pcar)//В 35 строке не неудачный каст, а просто не скомпилируется,
	//т.к. пытаемся достать адрес указателя + даже если бы просто стучались по указателю, 
	//классы не виртуальные (не полиморфные), поэтому ошибка компиляции.
	//downcast UB
	//Van* pvan = (Van*)&pcar;передача по ссылке обьекта даункаста не возможна
	return 0;
};
