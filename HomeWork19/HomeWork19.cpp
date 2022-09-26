#include <iostream>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

template <typename T>
void show_arr(T arr[], const int lenght) {
	cout << "[";
	for (int i = 0; i < lenght; i++)
		cout << arr[i] << ", ";
	cout << "\b\b]\n";
}

//Задача 1
int max_div(int a, int b)
{
	int max = 0;
	if (a >= b) {
		for (int i = 1; i <= a; i++)
			if (a % i == 0 and b % i == 0)
				max = i;
	}
	else {
		for (int i = 1; i <= b; i++)
			if (a % i == 0 and b % i == 0)
				max = i;
	}
	return max;
}

//Задача 2
void mirror_number(int num) {
	int counter = 0, k = num, m;
	do {
		k = k / 10;
		counter++;
	} while (k);
	k = 1;
	for (int i = 0; i < counter; i++) {
		m = num / k % 10;
		cout << m;
		k *= 10;
	}
}

//Задача 3
//Поиск первой позиции
template <typename T>
int search_index(T arr[], const int lenght, T value) {
	for (int i = 0; i < lenght; i++)
		if (arr[i] == value)
			return i;
	return -1;
}
//Сортировка
template <typename T>
void sort_range(T arr[], const int lenght, T N) {
	sort(arr + N + 1, arr + lenght);
}

//Задача 4
//Заполнение массива случайными числами
template <typename T>
void fill_arr(T arr[], const int lenght, int begin, int end) {
	srand(time(0));
	for (int i = 0; i < lenght; i++) {
		arr[i] = rand() % (end - begin) + begin;
	}
}


int main() {
	setlocale(LC_ALL, "ru");
	int n;

	//Задача 1
	/*cout << "Задача 1.\nВведите два числа: ";
	cin >> n >> m;
	cout << "Максимальный общий делитель = " << max_div(n, m) << endl;*/

	//Задача 2
	/*cout << "Задача 2.\nВведите число: ";
	cin >> n;
	mirror_number(n);*/

	//Задача 3
	cout << "Задача 2.\n";
	const int size = 10;
	int arr[size]{ 5, 6 , 10, 25, 1, 51, 37, 18, 84, 2 };
	cout << "Массив:\n";
	show_arr(arr, size);
	cout << "Введите число: ";
	cin >> n;

	if (search_index(arr, size, n) == -1)
		cout << "Такого числа нет в массиве.\n";
	else {
		cout << "Позиция числа в массиве: " << search_index(arr, size, n) << "\n";
		cout << "Итоговый массив: ";
		sort_range(arr, size, search_index(arr, size, n));
		show_arr(arr, size);
	}

	//Задача 4
	/*int A, B;
	cout << "Задача 4.\nВведите начало диапазона массива: ";
	cin >> A;
	cout << "Введите конец диапазона массива: ";
	cin >> B;
	int const size = 20;
	int arr[size];
	fill_arr(arr, size, A, B + 1);
	show_arr(arr, size);*/

	return 0;
}