#include <fstream>
#include <ctime>
#include <iostream>
#include "header.h"



//перегрузка операторов 
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



//Функция сортировки выбором. Возвращает количество секунд потраченное на сортировку
//Принимает в качестве аргументов массив, его длину и флаг проверки(для сортировки по убыванию/возрастанию)
double selectSort(flowers *arr, int size, bool F) {
	clock_t start = clock();//Замеряется время с начала выполнения функции
	double seconds;
	int k = 0;
	flowers x;
	for (int i = 0; i < size; i++) {
		for (int j = i + 1; j < size; j++) {
			if (F) {//флаг для сортиривки по убыванию 
				if (arr[i] > arr[j]) {
					x = arr[i];
					arr[i] = arr[j];
					arr[j] = x;
				}
			}
			else {//флаг для сортиривки по возрастанию
				if (arr[i] < arr[j]) {
					x = arr[i];
					arr[i] = arr[j];
					arr[j] = x;
				}
			}
		}
	}
	clock_t end = clock();//Отсановка замеренного времени
	return seconds = (double)(end - start) / CLOCKS_PER_SEC;
}



//вспомогательная функция пирамидальной сортировки 
//в качестве аргументов принимает массив, "номер корня пирамиды", правая граница пирамиды, флаг проверки(для сортировки по убыванию/возрастанию)
void siftDown(flowers *numbers, int root, int bottom, bool F) {
	int maxChild; // индекс максимального потомка
	int done = 0; // флаг того, что куча сформирована
	// Пока не дошли до последнего ряда
	while ((root * 2 <= bottom) && (!done)) {
		if (F) {
			if (root * 2 == bottom)    // если мы в последнем ряду,
				maxChild = root * 2;    // запоминаем левый потомок
			  // иначе запоминаем больший потомок из двух
			else if (numbers[root * 2] > numbers[root * 2 + 1])
				maxChild = root * 2;
			else
				maxChild = root * 2 + 1;
		}
		else {
			if (root * 2 == bottom)  // если мы в последнем ряду,
				maxChild = root * 2;  // запоминаем левый потомок
			// иначе запоминаем больший потомок из двух
			else if (numbers[root * 2] < numbers[root * 2 + 1])
				maxChild = root * 2;
			else
				maxChild = root * 2 + 1;
		}
		// если элемент вершины меньше максимального потомка
		if (F) {
			if (numbers[root] < numbers[maxChild]) {
				flowers temp = numbers[root]; // меняем их местами
				numbers[root] = numbers[maxChild];
				numbers[maxChild] = temp;
				root = maxChild;
			}
			else // иначе
				done = 1; // пирамида сформирована
		}
		else {
			if (numbers[root] > numbers[maxChild]) {
				flowers temp = numbers[root]; // меняем их местами
				numbers[root] = numbers[maxChild];
				numbers[maxChild] = temp;
				root = maxChild;
			}
			else // иначе
				done = 1; // пирамида сформирована
		}
	}
}





//Функция пиромидальной сортировки. Возвращает количество секунд потраченное на сортировку
//Принимает в качестве аргументов массив, его длину и флаг проверки(для сортировки по убыванию/возрастанию)
double heapSort(flowers *arr, int size, bool F) {
	clock_t start = clock();//Замеряется время с начала выполнения функции
	double seconds;
	// Формируем нижний ряд пирамиды
	for (int i = (size / 2) - 1; i >= 0; i--)
		if (F) {
			siftDown(arr, i, size - 1, true);
		}
		else {
			siftDown(arr, i, size - 1, false);
		}
	// Просеиваем через пирамиду остальные элементы
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
	clock_t end = clock();//Отсановка замеренного времени
	return seconds = (double)(end - start) / CLOCKS_PER_SEC;
}





//Функция для генерации массива и записи его в файл. Получает в аргуменет количество строк которое нужно сгенерировать 
void generator(int amount) {
	setlocale(LC_ALL, "rus");
	ofstream fin("C:/Users/nikit/OneDrive/Рабочий стол/База данных.txt");// создаём объект класса ofstream и связываем его с файлом
	if (!fin.is_open()) {
		cout << "Ошибка создания файла для генерации.";
		exit(1);
	}
	char str[50];//массив для генерируемых символов
	int t = 0;
	srand(time(NULL));
	for (int q = 0; q < amount; q++) {//цикл количества записиваемых строк в файл
		t = 0;
		for (int k = 0; k < 4; k++) {//цикл количества "слов" в строке
			int j = rand() % (10 - 5 + 1) + 5;//генерируемая длина слова(от 5 до 10 символов)
			for (int n = 0; n < j; ++n) {//цикл записи сгенерируемого символа в массив
				str[n + t] = rand() % ('z' - 'a' + 1) + 'a';//генерируется символы латинского алфавита
			}
			t += j;
			str[t] = ' ';//пробел между словами
			t++;
		}
		str[t - 1] = '\n';//символ перевода строки в конце строки
		str[t] = '\0';//терминальный символ после '\n'

		fin << str;//запись массива в файл
	}
	cout << "Генерация и запись в файл " << amount << " строк произошла успешно." << endl;
	fin.close();//закрытие файл
}






void generator_2(int a) {
	char name_1[10][15] = { "Гвоздика ", "Гиацинты ", "Герберы ", "Гладиолусы ", "Гортензия ", "Дельфиниум ", "Жасмин ", "Крокусы ", "Каллы ", "Лотос " };
	char color_1[10][15] = {"красный ", "желтый ", "зеленый ", "оранжевый ", "синий ", "розовый ", "белый ", "черный ", "фиолетовый ", "белый "};
	char aroma_1[3][9] = { "слабый ", "сильный ", "средний " };
	char area_1[10][20] = { "Кавказ\n", "Московская область\n", "Дальний восток\n", "Сибирь\n", "Поволжье\n", "Магадан\n", "Чечня\n", "Африка\n", "Европа\n", "Арктика\n", };
	ofstream fin("C:/Users/nikit/OneDrive/Рабочий стол/База данных.txt");// создаём объект класса ofstream и связываем его с файлом
	for (int i = 0; i < a; i++) {
		int f = rand() % (9 - 0 + 1) + 0;
		int s = rand() % (9 - 0 + 1) + 0;
		int t = rand() % (2 - 0 + 1) + 0;
		int fo = rand() % (9 - 0 + 1) + 0;
		fin << name_1[f] << color_1[s] << aroma_1[t] << area_1[fo];
	}
}