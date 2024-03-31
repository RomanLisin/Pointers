//DynamicMemory
#include<iostream>
using std::cin;
using std::cout;
using std::endl;

#define tab "\t"

void FillRand(int arr[], const int n);
void Print(const int arr[], const int n);

void main()
{
	setlocale(LC_ALL, "");
	int n = 5;
	cout << "Введите количество элементов: "; cin >> n;
	//1) Объявление динамического массива:
	int* arr = new int[n];

	//2) Обращение к элементам динамического массива:
	
	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;

	//1) создаем буферный массив нужного размераж

	int* buffer = new int[n + 1];

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];

	}
	delete[] arr;

	arr = buffer;

	arr[n] = value;
	n++;
	Print(arr, n);

	delete[] arr;

	arr[n] = value; //добавляем значение в конец массива
	n++;  // после добавления элемента в конец массива, количество его элементов увеличивается на один
	Print(arr, n);
	//3) Удаление динамического массива
	delete[] arr;



}
void FillRand(int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % 100; //обращение к элементам через арифметику указателей и оператор разименования
	}
}
void Print(const int arr[], const int n)
{
	for (int i = 0; i < n; i++)
	{
		cout << arr[i] << tab; //обращение к элементам через оператор индексирования
	}
}