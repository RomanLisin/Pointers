//DynamicMemory
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define nln cout << endl

void FillRand(int arr[], const int n);
void Print(const int arr[], const int n);
void Print(int** arr, int rows,  int cols);

int* push_back(int arr[], int& n, const int value);
int* push_front(int arr[], int& n, const int value);
int* pop_back(int arr[], int& n);
int* insert(int arr[], int& n, const int index, int value);
int* pop_front(int arr[], int& n);
int* erase(int arr[], int& n, const int index);

//#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_1_2
//#define DYNAMIC_MEMORY_2



void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n = 5;
	cout << "Введите количество элементов: "; cin >> n;
	//1) Объявление динамического массива:
	int* arr = new int[n];

	//2) Обращение к элементам динамического массива:

	FillRand(arr, n);
	Print(arr, n);

	int value;
	cout << "Введите добавляемое значение: "; cin >> value;

	arr = push_back(arr, n, value);

	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);

	delete[] arr;
#endif // DYNAMIC_MEMORY_1

	int i_arr_size = 0;
	int elmValue = 0;
	int elmIndex = 0;

	cout << "Введител количество элементов массива: "; cin >> i_arr_size; nln;
	cout << "Введите значение элемента для вставки: "; cin >> elmValue; nln;
	cout << "Введите индекс элемента для вставки значения: "; cin >> elmIndex; nln;

	int* arrX = new int[i_arr_size];
	FillRand(arrX, i_arr_size);
	cout << "Source array:\t\t\t\t";	Print(arrX, i_arr_size);

	arrX = push_back(arrX, i_arr_size,elmValue); nln;
	cout << "Add element " << elmValue << " to array back:\t\t"; Print(arrX, i_arr_size);

	arrX = push_front(arrX, i_arr_size, elmValue); nln;
	cout << "Add element "<< elmValue <<" to array front:\t\t"; Print(arrX, i_arr_size);

	arrX = insert(arrX, i_arr_size, elmIndex, elmValue); nln;
	cout << "Insert element " << elmValue << " to index "<<elmIndex<<" of array:\t"; Print(arrX, i_arr_size);

	arrX=pop_back(arrX, i_arr_size); nln;
	cout << "Del back element of array:\t\t"; Print(arrX, i_arr_size);nln;

	arrX=pop_front(arrX, i_arr_size);
	cout << "Del front element of array:\t\t"; Print(arrX, i_arr_size); nln;

	arrX=erase(arrX, i_arr_size, elmIndex);
	cout << "Del element " << elmIndex << " of array:\t\t\t"; Print(arrX, i_arr_size);

#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;

	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	///////////////////////////////////////////////////////////////////////////////
	///////////    Объявление двумероного динамического массива     ///////////////
	///////////////////////////////////////////////////////////////////////////////
	// 
	// 1) Создаём массив указателей:
	int** arr = new int* [rows];
	// 2) Выделяем память под строки: 
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new int[cols] {};
	}
	///////////////////////////////////////////////////////////////////////////////
	///////////      Использование двумероного динамического массива       ////////
	///////////////////////////////////////////////////////////////////////////////

	Print(arr, rows, cols);

	///////////////////////////////////////////////////////////////////////////////
	///////////        Удаление двумероного динамического массива          ////////
	///////////////////////////////////////////////////////////////////////////////

	// 1) Сначала удаляем строки двуменого массива
	for (int i = 0; i < rows; i++)
	{
		delete[] arr[i];
	}
	// 2) Удаляем массив указателей
	delete[] arr;

#endif // DYNAMIC_MEMORY_2


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
	nln;

}
void Print(int** arr, int rows, int cols)
{
	for(int i=0; i< rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab; //обращение к элементам через оператор индексирования
		}
		nln;
	}
}
int* push_back(int arr[],  int& n,const int value)
{
	//1) создаем буферный массив нужного размераж

	int* buffer = new int[n + 1];

	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i];

	}

	// 3) удаляем старый массив:

	delete[] arr;

	arr = buffer;

	// 5) Только после всего этого можно добавить значение в конец массива
	arr[n] = value;
	// 6) после добавления элемента в конец массива, количество его элементов увеличивается на 1
	n++;
	

	return arr;

}
int* push_front(int arr[], int& n, const int value)
{
	int* buffer = new int[n + 1];
	
	for (int i = 0; i < n; i++)
	{
		buffer[i+1] = arr[i];
	}
	delete[] arr;

	buffer[0] = value;
	n++;
	return buffer;

}
int* pop_back(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)*(buffer+i) = *(arr+i);
	delete[] arr;
	return buffer;
}
int* insert(int arr[], int& n, const int index, int value)
{
	int* buffer = new int[++n];
	for (int i = 0; i < n; i++)
	{
		if (i < index) buffer[i] = arr[i];
		else ((i == index)? buffer[i] = value: buffer[i] = arr[i-1]);	
	}
	delete[] arr;
	return buffer;
}
int* pop_front(int arr[], int& n)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	return buffer;
}
int* erase(int arr[], int& n, const int index)
{
	int* buffer = new int[--n];
	for (int i = 0; i < n; i++)
	{
		((i < index) ? buffer[i] = arr[i] : buffer[i] = arr[i + 1]);
	}
	delete[] arr;
	return buffer;
}