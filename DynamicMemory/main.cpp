﻿//DynamicMemory
//https://github.com/RomanLisin/Pointers.git
#include<iostream>

using std::cin;
using std::cout;
using std::endl;

#define tab "\t"
#define nln cout << endl

template<typename T>T** Allocate(const int rows, const int cols);
template<typename T> void Clear(T** arr, const int rows);

void FillRand(int arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(double arr[], const int n, int minRand = 0, int maxRand = 100);
void FillRand(int** arr, const int rows, const int cols, int minRand = 0, int maxRand = 100);
void FillRand(double** arr, const int rows,const int cols, int minRand = 0, int maxRand = 100);


template<typename T>void Print(const T arr[], const int cols);
template<typename T>void Print(T** arr,const int rows, const int cols);

//void Print(const int arr[], const int n);
//void Print(int** arr, int rows,  int cols);

template<typename T> T* push_back(T arr[], int& rows, const T value);
template<typename T>T* push_front(T arr[], int& rows, const T value);

template<typename T>T* pop_back(T arr[], int& rows);


template<typename T>T* insert(T arr[], int& rows, const int index, T value);


template<typename T>T* pop_front(T arr[], int& rows);
template<typename T>T* erase(T arr[], int& rows, const T index);

//template<typename T>T** Allocate(int rows, int cols);
//void Clear(int** arrMtrx, const int rows);
//int** push_row_back(int** arrMtrx, int& rows, int& cols, int* ar_Insert);
template<typename T>T** push_row_back(T** arr, int& rows, const int cols);
template<typename T>T** pop_row_back( T** arr, int& rows, const int cols);


template<typename T>T** push_row_front(T** arrMtrx, int& rows, int& cols, T* value);
template<typename T>T** insert_row(T** arrMtrx, int& rows, int& cols, T* ar_row, int index);
//int** pop_row_back(int** arrMtrx, int& rows, int& cols);

template<typename T>T** pop_row_front(T** arrMtrx, int& rows, int& cols);
template<typename T>T** erase_row(T** arrMtrx, int& rows, int& cols,int index);

//int** push_col_back(int** arrMtrx, int& rows, int& cols, int* ar_col);
template<typename T>void push_col_back(T** arrMtrx, const int rows, int& cols);
template<typename T> void pop_col_back(T** arr, const int rows, int& cols);

template<typename T>T** push_col_front(int** artMtrx, int& rows, int& cols, T* ar_col);
template<typename T>T** insert_col(int** artMtrx, int& rows, int& cols, T* ar_col, int index);
//int** pop_col_back(int** artMtrx, int& rows, int& cols);
template<typename T>T** pop_col_front(T** artMtrx, int& rows, int& cols);
template<typename T>T** erase_col(T** artMtrx, int& rows, int& cols, int index);

template<typename T> void push_col_back(T** arr, const int rows, int& cols)
{
	for(int i=0;i<rows;i++)
	{
		T* buffer = new T[cols + 1] {};
		for (int j = 0; j < cols; j++) buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
	cols++;
}

#define DYNAMIC_MEMORY_1
//#define DYNAMIC_MEMORY_1_HOME
//#define DYNAMIC_MEMORY_2
//#define DYNAMIC_MEMORY_HOUSE_WORK
//#define PERFORMANCE_CHEK



void main()
{
	setlocale(LC_ALL, "");
#ifdef DYNAMIC_MEMORY_1
	int n = 5;
	cout << "Введите количество элементов: "; cin >> n;
	//1) Объявление динамического массива:
	double* arr = new double[n];
	//int* arr = new int[n];

	//2) Обращение к элементам динамического массива:

	FillRand(arr, n);
	Print(arr, n);

	double value;
	cout << "Введите добавляемое значение: "; cin >> value;

	arr = push_back(arr, n, value);

	Print(arr, n);

	cout << "Введите добавляемое значение: "; cin >> value;
	arr = push_front(arr, n, value);
	Print(arr, n);

	arr = pop_back(arr, n);
	Print(arr, n);
	//3)  Удаление динамического массива
	delete[] arr;

		// Memory Leak
#endif // DYNAMIC_MEMORY_1

#ifdef DYNAMIC_MEMORY_1_HOME
	int i_arr_size = 0;
	int elmValue = 0;
	int elmIndex = 0;

	cout << "Введител количество элементов массива: "; cin >> i_arr_size; nln;
	cout << "Введите значение элемента для вставки: "; cin >> elmValue; nln;
	cout << "Введите индекс элемента для вставки значения: "; cin >> elmIndex; nln;

	int* arrX = new int[i_arr_size];
	FillRand(arrX, i_arr_size);
	cout << "Source array:\t\t\t\t";	Print(arrX, i_arr_size);

	arrX = push_back(arrX, i_arr_size, elmValue); nln;
	cout << "Add element " << elmValue << " to array back:\t\t"; Print(arrX, i_arr_size);

	arrX = push_front(arrX, i_arr_size, elmValue); nln;
	cout << "Add element " << elmValue << " to array front:\t\t"; Print(arrX, i_arr_size);

	arrX = insert(arrX, i_arr_size, elmIndex, elmValue); nln;
	cout << "Insert element " << elmValue << " to index " << elmIndex << " of array:\t"; Print(arrX, i_arr_size);

	arrX = pop_back(arrX, i_arr_size); nln;
	cout << "Del back element of array:\t\t"; Print(arrX, i_arr_size); nln;

	arrX = pop_front(arrX, i_arr_size);
	cout << "Del front element of array:\t\t"; Print(arrX, i_arr_size); nln;

	arrX = erase(arrX, i_arr_size, elmIndex);
	cout << "Del element " << elmIndex << " of array:\t\t\t"; Print(arrX, i_arr_size);
#endif // DYNAMIC_MEMORY_1_HOME


#ifdef DYNAMIC_MEMORY_2
	int rows;
	int cols;

	cout << "Введите количество строк: "; cin >> rows;
	cout << "Введите количество элементов строки: "; cin >> cols;

	double** arr = Allocate<double>(rows, cols);
	///////////////////////////////////////////////////////////////////////////////
	///////////    Использование двумероного динамического массива     ///////////////
	///////////////////////////////////////////////////////////////////////////////
	
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);

	arr = push_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	arr = pop_row_back(arr, rows, cols);
	Print(arr, rows, cols);

	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	
	Clear(arr, rows);

	
	///////////////////////////////////////////////////////////////////////////////
	///////////      Использование двумероного динамического массива       ////////
	///////////////////////////////////////////////////////////////////////////////

	Print(arr, rows, cols);

	

#endif // DYNAMIC_MEMORY_2
#ifdef DYNAMIC_MEMORY_HOUSE_WORK

	int rows = 0;
	int cols = 0;
	int xIndex = 2;


	cout << "Input quantity of rows:\t"; cin >> rows;
	cout << "Input quantity of cols:\t"; cin >> cols; nln;

	int* arr_111 = new int[rows];
	for (int i = 0; i < rows; i++)
	{
		arr_111[i] = 1;
	}

	int** arrTwoDim = allocate(rows, cols);
	FillRand(arrTwoDim, rows, cols);
	Print(arrTwoDim, rows, cols);
	cout << rows << " rows, " << cols << " cols, allocate done"; nln; nln;

	arrTwoDim = push_row_back(arrTwoDim, rows, cols, arr_111);
	Print(arrTwoDim, rows, cols);
	cout << rows << " rows, " << cols << " cols, push_row_back done"; nln; nln;

	arrTwoDim = push_row_front(arrTwoDim, rows, cols, arr_111);
	Print(arrTwoDim, rows, cols);
	cout << rows << " rows, " << cols << " cols, push_row_front done" << endl; nln;

	int* arr_222 = new int[rows];
	for (int i = 0; i < rows; i++)
	{
		arr_222[i] = 7;
	}

	int** arrRowIns = allocate(rows, cols);
	Print(arrRowIns, rows, cols);
	cout << rows << " rows, " << cols << " cols, allocate done " << endl; nln;

	FillRand(arrRowIns, rows, cols);
	int** arrInsert = insert_row(arrRowIns, rows, cols, arr_222, xIndex);
	Print(arrInsert, rows, cols);
	cout << rows << " rows, " << cols << " cols, insert_row done" << endl; nln;

	arrInsert = erase_row(arrInsert, rows, cols, xIndex);
	Print(arrInsert, rows, cols);
	cout << rows << " rows, " << cols << " cols, erase_row done" << endl; nln;

	arrInsert = pop_row_back(arrInsert, rows, cols);
	Print(arrInsert, rows, cols);
	cout << rows << " rows, " << cols << " cols, pop_row_back done" << endl; nln;

	arrInsert = pop_row_front(arrInsert, rows, cols);
	Print(arrInsert, rows, cols);
	cout << rows << " rows, " << cols << " cols, pop_row_front done" << endl; nln;

	arrInsert = push_col_back(arrInsert, rows, cols, arr_222);
	Print(arrInsert, rows, cols);
	cout << rows << "rows, " << cols << " cols, push_col_back done" << endl; nln;

	arrInsert = push_col_front(arrInsert, rows, cols, arr_222);
	Print(arrInsert, rows, cols);
	cout << rows << "rows, " << cols << " cols, push_col_front done" << endl; nln;

	arrInsert = insert_col(arrInsert, rows, cols, arr_222, xIndex);
	Print(arrInsert, rows, cols);
	cout << rows << "rows, " << cols << " cols, insert_col done" << endl; nln;

#endif // DYNAMIC_MEMORY_HOUSE_WORK

#ifdef PERFORMANCE_CHEK
	int rows;
	int cols;

	cout << "Input number of rows: "; cin >> rows;
	cout << "Input number of cols: "; cin >> cols;
	int** arr = Allocate(rows, cols);
	FillRand(arr, rows, cols);
	Print(arr, rows, cols);
	//system("pause");
	arr = push_row_back(arr, rows, cols);
	Print(arr, rows, cols);
	arr = pop_row_back(arr, rows, cols);
	FillRand(arr[rows - 1], cols, 100, 1000);
	Print(arr, rows, cols);

	push_col_back(arr, rows, cols);
	Print(arr, rows, cols);

	pop_col_back(arr, rows, cols);
	Print(arr, rows, cols);
	
	Clear(arr, rows);
#endif // PERFORMANCE_CHEK

}

//void FillRand(double arr[], )     Дописать для double  10:30:00


template<typename T>T** Allocate(const int rows, const int cols) {
	
	
	    ///////////////////////////////////////////////////////////////////////////
		///////////    Объявление двумероного динамического массива     ///////////////
		///////////////////////////////////////////////////////////////////////////////
		
		// 1) Создаём массив указателей:
	T** arr = new T* [rows];
	// 2) Выделяем память под строки: 
	for (int i = 0; i < rows; i++)
	{
		arr[i] = new T[cols] {};
	}
	return arr;
}
template<typename T>void Clear(T** arr, const int rows) {
	
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
}

void FillRand(int arr[], const int n, int minRand, int maxRand)
{
	for (int i = 0; i < n; i++)
	{
		*(arr + i) = rand() % (maxRand - minRand) + minRand; //обращение к элементам через арифметику указателей и оператор разименования
	}
}
void FillRand(double arr[], const int n, int minRand, int maxRand)
{
	if (minRand > maxRand)
	{
		int buffer = minRand;
		minRand *= 100;
		maxRand *= 100;
		for (int i=0;i <n; i++)
		{
			*(arr + i) = rand() % (maxRand - minRand) + minRand;
			arr[i] /= 100;
		}
	}	
}
void FillRand(int** arr, const int rows, const int cols, int minRand, int maxRand)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % (maxRand - minRand) + minRand;
		}
	}
}
void FillRand(double** arr, const int rows, const int cols, int minRand, int maxRand)
	{   
		if (minRand > maxRand)
		{
			int buffer = minRand;
			minRand = maxRand;
			maxRand = buffer;
		}
		minRand *= 100;
		maxRand *= 100;
		for(int i=0;i<rows;i++)
		{
			for (int j = 0; j < cols; j++)
			{
				arr[i][j] = rand() % (maxRand - minRand) + minRand;
				arr[i][j] /= 100;
			}
		}
}
//void Print(const int arr[], const int n)
template<typename T>void Print(const T arr[], const int cols)
{
	for (int i = 0; i < cols; i++)
	{
		cout << arr[i] << tab; //обращение к элементам через оператор индексирования
	}
	nln;

}

//void Print(int** arr, int rows, int cols)
template<typename T>void Print(T** arr,const int rows, const int cols)
{
	for(int i=0; i< rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << tab; //обращение к элементам через оператор индексирования
		}
		nln;
	}
	nln;
}
template<typename T>T* push_back(T arr[],  int& rows,const T value)
{
	//1) создаем буферный массив нужного размераж

	T* buffer = new T[rows + 1];

	for (int i = 0; i < rows; i++)
	{
		buffer[i] = arr[i];

	}

	// 3) удаляем старый массив:

	delete[] arr;

	arr = buffer;

	// 5) Только после всего этого можно добавить значение в конец массива
	arr[rows] = value;
	// 6) после добавления элемента в конец массива, количество его элементов увеличивается на 1
	rows++;
	

	return arr;

}
template<typename T>T* push_front(int arr[], int& n, const int value)
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
template<typename T>T* pop_back(T arr[], int& n)
{
	T buffer = new T[--n];
	for (int i = 0; i < n; i++)*(buffer+i) = *(arr+i);
	delete[] arr;
	return buffer;
}
template<typename T>T* insert(T arr[], int& n, const int index, int value)
{
	T* buffer = new T[++n];
	for (int i = 0; i < n; i++)
	{
		if (i < index) buffer[i] = arr[i];
		else ((i == index)? buffer[i] = value: buffer[i] = arr[i-1]);	
	}
	delete[] arr;
	return buffer;
}
template<typename T>T* pop_front(T arr[], int& n)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = arr[i + 1];
	}
	delete[] arr;
	return buffer;
}
template<typename T>T* erase(T arr[], int& n, const int index)
{
	T* buffer = new T[--n];
	for (int i = 0; i < n; i++)
	{
		((i < index) ? buffer[i] = arr[i] : buffer[i] = arr[i + 1]);
	}
	delete[] arr;
	return buffer;
}
//int** Allocate(const int rows, const int cols)
//{
//	int** arr = new int* [rows];    // create array of pointers 
//	for (int i = 0; i < rows; i++)
//	{
//		arr[i] = new int[cols] {}; // create cols
//	}
//	return arr;
//}
//void Clear(int** arrMtrx,const int rows)
//{
//	for (int i = 0; i < rows; i++)
//	{
//		delete[] arrMtrx[i];  // del rows of array
//	}
//	delete[] arrMtrx; // del pointer to array
//}
template<typename T>T** push_row_back(T** arr, int& rows, const int cols)
{
	T** buffer = new T * [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	buffer[rows] = new T[cols]{};
	rows++;
	return buffer;
}
template<typename T>T** push_row_front(T** arrMtrx, int& rows, const int cols)  // check
{

	T** buffer = new T * [rows + 1];
	for (int i = 0; i < rows; i++)buffer[i+1] = arr[i];
	delete[] arr;
	buffer[rows] = new T[cols]{};
	rows++;
	return buffer;


	//int** buffer = Allocate(rows+1, cols);   // allocate memory for the buffer array
	//for (int i = 0; i < rows; i++)
	//{
	//	for (int j = 0; j < cols; j++)
	//	{
	//		buffer[i+1][j] = arrMtrx[i][j];  // copy the values from the source to the buffer array
	//	}
	//}
	//Clear(arrMtrx, rows);  //  delete souce array
	//arrMtrx = buffer;				// copy reference
	////arrMtrx[0] = new int[cols];     // allocate memory for the row to insert
	//for (int j = 0; j < cols; j++)
	//{
	//	arrMtrx[0][j] = value[j];   // copy value from insert row to the first row of the array
	//}
	//++rows; 
	//return arrMtrx;
}
int** insert_row(int** arrMtrx, int& rows, int& cols, int* ar_row, int index)   // change and check
{
	//int** buffer = allocate(rows + 1, cols);
	int** buffer = new int* [rows + 1];
	for (int i = 0; i < rows + 1; i++)
	{
		buffer[i] = new int[cols];
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{

			buffer[i][j] = arrMtrx[i][j];    // ПОСМОТРЕТЬ, возможно УМЕНЬШИТЬ КОЛ-ВО ИТЕРАЦИЙ
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (index <= i) buffer[i + 1][j] = arrMtrx[i][j];
		}
	}

	for (int j = 0; j < cols; j++)
	{
		buffer[index][j] = ar_row[j];
	}
	//Clear(arrMtrx, rows);
	for (int i = 0; i < rows; i++)
	{
		delete[] arrMtrx[i];
	}
	delete[] arrMtrx;
	++rows;
	return buffer;
}
//int** pop_row_back(int** arrMtrx, int& rows, int& cols)
//{
//	int** buffer = Allocate(rows-1, cols);
//	for (int i = 0; i < rows-1; i++)
//	{
//		buffer[i] = new int[cols];
//	}
//	for (int i = 0; i < rows-1; i++)
//	{
//		for (int j = 0; j < cols; j++)
//		{
//			buffer[i][j] = arrMtrx[i][j];
//		}
//	}
//	Clear(arrMtrx, rows);
//	--rows;
//	return buffer;
//}
int** pop_row_front(int** arrMtrx, int& rows, int& cols)   // change and check
{
	int** buffer = Allocate(rows-1, cols);
	for (int i = 0; i < rows-1; i++)
	{
		buffer[i] = new int[cols];
	}
	for (int i = 0; i < rows-1; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			 buffer[i][j] = arrMtrx[i + 1][j];
		}
	}
	Clear(arrMtrx, rows);
	--rows;
	return buffer;
}
int** erase_row(int** arrMtrx, int& rows, int& cols, int index)             // change and check
{
	//int** buffer = allocate(rows + 1, cols);
	int** buffer = new int* [rows-1];
	for (int i = 0; i < rows-1; i++)
	{
		buffer[i] = new int[cols];
	}
	for (int i = 0; i < rows-1; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			((index > i) ? buffer[i][j] = arrMtrx[i][j] : buffer[i][j]=arrMtrx[i+1][j]);
		}
	}
	//Clear(arrMtrx, rows);
	for (int i = 0; i < rows; i++)
	{
		delete[] arrMtrx[i];
	}
	delete[] arrMtrx;
	--rows;
	return buffer;
}
//int** push_col_back(int** arrMtrx, int& rows, int& cols, int* ar_col)
//{
//	int** buffer = Allocate(rows, cols+1);
//	for (int i = 0; i < rows; i++)
//	{
//		buffer[i] = new int[cols + 1];
//	}
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols + 1; j++)
//		{
//			buffer[i][j] = arrMtrx[i][j];
//		}
//	}
//	Clear(arrMtrx, rows);
//	for (int i = 0; i < rows; i++)
//	{
//			buffer[i][cols] = ar_col[i];
//	}
//	++cols;
//	return buffer;
//}
int** push_col_front(int** arrMtrx, int& rows, int& cols, int* ar_col)
{
	int** buffer = Allocate(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols + 1];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols + 1; j++)
		{
			buffer[i][j+1] = arrMtrx[i][j];
		}
	}
	Clear(arrMtrx, rows);
	for (int i = 0; i < rows; i++)
	{
		buffer[i][0] = ar_col[i];
	}
	++cols;
	return buffer;
}
int** insert_col(int** arrMtrx, int& rows, int& cols, int* ar_col, int index)    // change and check
{
	int** buffer = Allocate(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols+1];
	}


	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			buffer[i][j] = arrMtrx[i][j]; // ПОСМОТРЕТЬ, УМЕНЬШИТЬ КОЛ-ВО ИТЕРАЦИЙ
		}
	}

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (index <= i) buffer[i][j+1] = arrMtrx[i][j];
		}
	}

	for (int i = 0; i < cols; i++)
	{
		buffer[i][cols] = ar_col[i];
	}


	Clear(arrMtrx, rows);
	++cols;
	return buffer;
}
//int** pop_col_back(int** arrMtrx, int& rows, int& cols)
//{
//	int** buffer = Allocate(rows, cols);
//	for (int i = 0; i < rows; i++)
//	{
//		buffer[i] = new int[cols - 1];
//	}
//	for (int i = 0; i < rows; i++)
//	{
//		for (int j = 0; j < cols - 1; j++)
//		{
//			buffer[i][j] = arrMtrx[i][j];
//		}
//	}
//	Clear(arrMtrx, rows);
//	--cols;
//	return buffer;
//}
int** pop_col_front(int** arrMtrx, int& rows, int& cols)     // change and check
{
	int** buffer = Allocate(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols - 1];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols-1; j++)
		{
			((j==0) ? buffer[i][j] = arrMtrx[i][j] : buffer[i][j] = arrMtrx[i][j + 1]);
		}
	}
	Clear(arrMtrx, rows);
	--cols;
	return buffer;
}
int** erase_col(int** arrMtrx, int& rows, int& cols, int index)          // change and check
{
	int** buffer = Allocate(rows, cols);
	for (int i = 0; i < rows; i++)
	{
		buffer[i] = new int[cols - 1];
	}
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols-1; j++)
		{
			((index > j) ? buffer[i][j] = arrMtrx[i][j] : buffer[i][j] = arrMtrx[i][j + 1]);
		}
	}
	Clear(arrMtrx, rows);
	--cols;
	return buffer;
}

template<typename T> T** pop_row_back(T** arr, int& rows, const int cols)         // check
{
	T** buffer = new T* [--rows];
	delete[] arr[rows]; // удаляем из памяти последнюю строку двумерного массива
	for (int i = 0; i < rows; i++)buffer[i] = arr[i];
	delete[] arr;
	return buffer;
}
template<typename T> void pop_col_back(T** arr, const int rows, int& cols)     // check
{
	cols--;
	for (int i = 0; i < rows; i++)
	{
		T* buffer = new T[cols] {};
		for (int j = 0; j < cols; j++)buffer[j] = arr[i][j];
		delete[] arr[i];
		arr[i] = buffer;
	}
}