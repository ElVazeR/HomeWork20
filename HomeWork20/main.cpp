#include <iostream>
#include <cstdlib>
#include <ctime>

template <typename T>
void fill_arr(T arr[], const int length, int left, int right) {
	srand(time(NULL));
	for (int i = 0; i < length; i++)
		arr[i] = rand() % (right - left) + left;
}

template <typename T>
void print_arr(T arr[], const int length) {
	std::cout << "{ ";
	for (int i = 0; i < length; i++)
		std::cout << arr[i] << ", ";
	std::cout << "\b\b }\n";
}

template <typename T>
int search_index(T arr[], const int length, T key, int begin = 0) {
	for (int i = begin; i < length; i++)
		if (arr[i] == key)
			return i;
	return -1;
}

//Функция линейного поиска ПОСЛЕДНЕГО вхождения значения key в массив arr
template<typename T>
int search_last_index(T arr[], const int length, T key) {
	for (int i = length - 1; i >= 0; i--)
		if (arr[i] == key)
			return i;
	return -1; // Возвращаем значение "-1" в том случае если нужного числа нет в массиве.
}
//Функция линейного поиска ПОСЛЕДНЕГО вхождения значения key в массив arr c позиции begin.
template<typename T>
int search_last_index(T arr[], const int length, T key, int begin) {
	for (int i = begin; i >= 0; i--)
		if (arr[i] == key)
			return i;
	return -1; // Возвращаем значение "-1" в том случае если нужного числа нет в массиве.
}


template <typename T>
int arr_min(T arr, const int length) {
	int min = arr[0];
	for (int i = 0; i < length; i++)
		if (arr[i] < min)
			min = arr[i];
	return min;
}

template <typename T>
int arr_max(T arr, const int length) {
	int max = arr[0];
	for (int i = 0; i < length; i++)
		if (arr[i] > max)
			max = arr[i];
	return max;
}

template <typename T>
double mean_value(T arr, const int length) {
	int sum = 0;
	for (int i = 0; i < length; i++)
		sum += arr[i];
	return double(sum) / length;
}
// НЕПРАВИЛЬНО ВЫВОДИТ ДИАПАЗОН!
void range(int arr[], const int length, int left, int right) {
	for (int i = left; i < right; i++)
			
		std::cout << arr[i] << ", ";
}

template <typename T>
int count(int arr[], const int length, T key) {
	int count = 0;
	for (int i = 0; i < length; i++)
		if (arr[i] == key)
			count++;
	return count;
}

template <typename T>
void bubble_sort(T arr[], const int length) {
	for (int i = length - 1; i > 0; i--)
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1])
				std::swap(arr[j], arr[j + 1]);
		}
}





int main() {
	setlocale(LC_ALL, "russian");
	std::cout << "Массив: ";
	const int size = 10;
	int arr[size];
	fill_arr(arr, size, -1, 25);
	print_arr(arr, size);
	int n, m;
	std::cout << "\nВведите число: ";
	std::cin >> n;
	std::cout << "Индекс первого вхождения  числа - " << search_index(arr, size, n);
	std::cout << std::endl;
	std::cout << "Введите число: ";
	std::cin >> m;
	std::cout << "Индекс последнего вхождения числа - " << search_last_index(arr, size, n);
	std::cout << std::endl;
	std::cout << "Минимальное значение массива    = " << arr_min(arr, size);
	std::cout << std::endl;
	std::cout << "Минимальное значение массива    = " << arr_max(arr, size);
	std::cout << std::endl;
	std::cout << "Среднее арифметическое массива  = " << mean_value(arr, size);
	std::cout << std::endl;
	std::cout << "Введите начало диапазона -> ";
	std::cin >> n;
	std::cout << "Введите конец диапазона  -> ";
	std::cin >> m;
	std::cout << "Элементы в диапазоне: ";
	range(arr, size, n, m);
	std::cout << std::endl;
	std::cout << "Выберите число: ";
	std::cin >> n;
	std::cout << "Колличество вхождений этого элемента в массив: " << count(arr, size, n);
	std::cout << std::endl;
	std::cout << "Отсортированный массив: ";
	bubble_sort(arr, size);
	print_arr(arr, size);


	return 0;
}