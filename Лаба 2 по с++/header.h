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
	flowers() {//����������� ��� ����������
		name = "";
		color = "";
		aroma = "";
		area = "";
	}
	flowers(string obj) {//����������� ��� ���������� 
		fill(obj);
	}
	void fill(string obj) {//����� ���������� ������ �� ������� ������
		int first = obj.find(" ");//����� ������ ����������� ������� � �������(�.�. ������������ "�����" �������� � ���� ����� ������)
		name = obj.substr(0, first);//��������� ��������� � ������� ������ substr

		int second = obj.find(" ", first + 1);
		color = obj.substr(first + 1, second - first);

		int third = obj.find(" ", second + 1);
		aroma = obj.substr(second + 1, third - second);

		area = obj.substr(third + 1, obj.length() - 1);
	}
	//���������� ������������� �������
	friend bool operator < (const flowers x, const flowers y);
	friend bool operator > (const flowers x, const flowers y);
	friend bool operator >= (const flowers x, const flowers y);
	friend bool operator <= (const flowers x, const flowers y);
	friend ostream& operator << (ostream& out, const flowers &y);
};



double selectSort(flowers *, int, bool);//������� ����������� �������
double heapSort(flowers *, int, bool);//������� ����������� ������������
void generator(int);//�������� ������� ���������
void generator_2(int);