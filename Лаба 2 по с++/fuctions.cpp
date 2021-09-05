#include <fstream>
#include <ctime>
#include <iostream>
#include "header.h"



//���������� ���������� 
bool operator < (const flowers x, const flowers y) {
	if (x.name == y.name) {
		return x.color < y.color;
	}
	return x.name < y.name;
}

bool operator > (const flowers x, const flowers y) {
	if (x.name == y.name) {
		return x.color > y.color;
	}
	return x.name > y.name;
}

bool operator <= (const flowers x, const flowers y) {
	return x.name <= y.name;
}

bool operator >= (const flowers x, const flowers y) {
	return x.name >= y.name;
}

ostream& operator << (ostream& out, const flowers &a) {
	out << a.name << " " << a.color << "" << a.aroma << "" << a.area << "\n";
	return out;
}



//������� ���������� �������. ���������� ���������� ������ ����������� �� ����������
//��������� � �������� ���������� ������, ��� ����� � ���� ��������(��� ���������� �� ��������/�����������)
double selectSort(flowers *arr, int size, bool F) {
	clock_t start = clock();//���������� ����� � ������ ���������� �������
	double seconds;
	int k = 0;
	flowers x;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (F) {//���� ��� ���������� �� �������� 
				if (arr[i] > arr[j]) {
					x = arr[i];
					arr[i] = arr[j];
					arr[j] = x;
				}
			}
			else {//���� ��� ���������� �� �����������
				if (arr[i] < arr[j]) {
					x = arr[i];
					arr[i] = arr[j];
					arr[j] = x;
				}
			}
		}
	}
	clock_t end = clock();//��������� ����������� �������
	return seconds = (double)(end - start) / CLOCKS_PER_SEC;
}



//��������������� ������� ������������� ���������� 
//� �������� ���������� ��������� ������, "����� ����� ��������", ������ ������� ��������, ���� ��������(��� ���������� �� ��������/�����������)
void siftDown(flowers *numbers, int root, int bottom, bool F) {
	int maxChild; // ������ ������������� �������
	int done = 0; // ���� ����, ��� ���� ������������
	// ���� �� ����� �� ���������� ����
	while ((root * 2 <= bottom) && (!done)) {
		if (F) {
			if (root * 2 == bottom)    // ���� �� � ��������� ����,
				maxChild = root * 2;    // ���������� ����� �������
			  // ����� ���������� ������� ������� �� ����
			else if (numbers[root * 2] > numbers[root * 2 + 1])
				maxChild = root * 2;
			else
				maxChild = root * 2 + 1;
		}
		else {
			if (root * 2 == bottom)  // ���� �� � ��������� ����,
				maxChild = root * 2;  // ���������� ����� �������
			// ����� ���������� ������� ������� �� ����
			else if (numbers[root * 2] < numbers[root * 2 + 1])
				maxChild = root * 2;
			else
				maxChild = root * 2 + 1;
		}
		// ���� ������� ������� ������ ������������� �������
		if (F) {
			if (numbers[root] < numbers[maxChild]) {
				flowers temp = numbers[root]; // ������ �� �������
				numbers[root] = numbers[maxChild];
				numbers[maxChild] = temp;
				root = maxChild;
			}
			else // �����
				done = 1; // �������� ������������
		}
		else {
			if (numbers[root] > numbers[maxChild]) {
				flowers temp = numbers[root]; // ������ �� �������
				numbers[root] = numbers[maxChild];
				numbers[maxChild] = temp;
				root = maxChild;
			}
			else // �����
				done = 1; // �������� ������������
		}
	}
}





//������� ������������� ����������. ���������� ���������� ������ ����������� �� ����������
//��������� � �������� ���������� ������, ��� ����� � ���� ��������(��� ���������� �� ��������/�����������)
double heapSort(flowers *arr, int size, bool F) {
	clock_t start = clock();//���������� ����� � ������ ���������� �������
	double seconds;
	// ��������� ������ ��� ��������
	for (int i = (size / 2) - 1; i >= 0; i--)
		if (F) {
			siftDown(arr, i, size - 1, true);
		}
		else {
			siftDown(arr, i, size - 1, false);
		}
	// ���������� ����� �������� ��������� ��������
	for (int i = size - 1; i >= 1; i--) {
		flowers temp = arr[0];
		arr[0] = arr[i];
		arr[i] = temp;
		if (F) {
			siftDown(arr, 0, i - 1, true);
		}
		else {
			siftDown(arr, 0, i - 1, false);
		}
	}
	clock_t end = clock();//��������� ����������� �������
	return seconds = (double)(end - start) / CLOCKS_PER_SEC;
}





//������� ��� ��������� ������� � ������ ��� � ����. �������� � ��������� ���������� ����� ������� ����� ������������� 
void generator(int amount) {
	setlocale(LC_ALL, "rus");
	ofstream fin("C:/Users/nikit/OneDrive/������� ����/���� ������.txt");// ������ ������ ������ ofstream � ��������� ��� � ������
	if (!fin.is_open()) {
		cout << "������ �������� ����� ��� ���������.";
		exit(1);
	}
	char str[50];//������ ��� ������������ ��������
	int t = 0;
	srand(time(NULL));
	for (int q = 0; q < amount; q++) {//���� ���������� ������������ ����� � ����
		t = 0;
		for (int k = 0; k < 4; k++) {//���� ���������� "����" � ������
			int j = rand() % (10 - 5 + 1) + 5;//������������ ����� �����(�� 5 �� 10 ��������)
			for (int n = 0; n < j; ++n) {//���� ������ �������������� ������� � ������
				str[n + t] = rand() % ('z' - 'a' + 1) + 'a';//������������ ������� ���������� ��������
			}
			t += j;
			str[t] = ' ';//������ ����� �������
			t++;
		}
		str[t - 1] = '\n';//������ �������� ������ � ����� ������
		str[t] = '\0';//������������ ������ ����� '\n'

		fin << str;//������ ������� � ����
	}
	cout << "��������� � ������ � ���� " << amount << " ����� ��������� �������." << endl;
	fin.close();//�������� ����
}






void generator_2(int a) {
	char name_1[10][15] = { "�������� ", "�������� ", "������� ", "���������� ", "��������� ", "���������� ", "������ ", "������� ", "����� ", "����� " };
	char color_1[10][15] = {"������� ", "������ ", "������� ", "��������� ", "����� ", "������� ", "����� ", "������ ", "���������� ", "����� "};
	char aroma_1[3][9] = { "������ ", "������� ", "������� " };
	char area_1[10][20] = { "������\n", "���������� �������\n", "������� ������\n", "������\n", "��������\n", "�������\n", "�����\n", "������\n", "������\n", "�������\n", };
	ofstream fin("C:/Users/nikit/OneDrive/������� ����/���� ������.txt");// ������ ������ ������ ofstream � ��������� ��� � ������
	for (int i = 0; i < a; i++) {
		int f = rand() % (9 - 0 + 1) + 0;
		int s = rand() % (9 - 0 + 1) + 0;
		int t = rand() % (2 - 0 + 1) + 0;
		int fo = rand() % (9 - 0 + 1) + 0;
		fin << name_1[f] << color_1[s] << aroma_1[t] << area_1[fo];
	}
}