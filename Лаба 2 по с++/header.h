#pragma once
#include <string>

using namespace std;

class flowers {
private:
	string name;
	string color;
	string aroma;
	string area;
public:
	flowers() {//конструктор дл€ объ€влени€
		name = "";
		color = "";
		aroma = "";
		area = "";
	}
	flowers(string obj) {//конструктор дл€ заполнени€ 
		fill(obj);
	}
	void fill(string obj) {//метод разделени€ строки на объекты класса
		int first = obj.find(" ");//поиск номера пробельного символа в массиве(т.к. генерируемые "слова" записаны в файл через пробел)
		name = obj.substr(0, first);//выделение подстроки с помощью метода substr

		int second = obj.find(" ", first + 1);
		color = obj.substr(first + 1, second - first);

		int third = obj.find(" ", second + 1);
		aroma = obj.substr(second + 1, third - second);

		area = obj.substr(third + 1, obj.length() - 1);
	}
	//объ€вление дружественных функций
	friend bool operator < (const flowers x, const flowers y);
	friend bool operator > (const flowers x, const flowers y);
	friend bool operator >= (const flowers x, const flowers y);
	friend bool operator <= (const flowers x, const flowers y);
	friend ostream& operator << (ostream& out, const flowers &y);
};



double selectSort(flowers *, int, bool);//функци€ сортирующа€ выбором
double heapSort(flowers *, int, bool);//функци€ сортирующа€ пирамидально
void generator(int);//прототип функции генерации
void generator_2(int);