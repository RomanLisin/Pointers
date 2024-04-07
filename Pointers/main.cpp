//Pointers
#include<iostream>
using namespace std;
//#define POINTERS_BASICS


void Print(int** arr, int rows, int cols);
void FillRand(int** arr, int rows, int cols);
int** insert_row(int** arrMtrx, int& rows, int& cols, int* ar_row, int index);
void _insert_row(int** arrMtrx, int& rows, int& cols, int* ar_row, int index);


void main() {

	setlocale(LC_ALL, "");

#ifdef POINTERS_BASICS
	int a = 2; // объявление  переменной 'a' типа 'int'
	int* pa = &a; // указатель  можем проинициализировать только адресом
	cout << a << endl;  // вывод значения переменной 'a' на экран
	cout << &a << endl; // взятие адреса переменной 'a' прямо при выводе
	cout << pa << endl; // вывод адреса переменной 'a', хранящегося в указателе 'pa'
	cout << *pa << endl;  // разыменование указателя 'pa' и вывод на экран значения по адресу в этом указателе
	cout << pa[0] << endl;  // разыменование указателя 'pa' и вывод на экран значения по адресу в этом указателе

	/*const int n = 5;
	short arr[n] = { 3,5,8,13,21 };
	cout << arr << endl;
	cout << *arr << endl;

	for (int i = 0; i < n; i++)
	{
		cout << *(arr + i) << "\t";
	}

	cout << endl;*/

#endif // POINTERS_BASICS

	int i_rows = 3;
	int i_cols = 3;
	int xIndex = 2;

	int** ar_Isrt_Indx = new int* [i_rows];
	for (int i = 0; i < i_rows; i++)
	{
		ar_Isrt_Indx[i] = new int[i_cols] ;
	}
	int* xArr = new int[i_rows];
	for (int i = 0; i < i_rows; i++)
	{
		xArr[i] = xIndex;
	}


	FillRand(ar_Isrt_Indx, i_rows, i_cols);
	Print(ar_Isrt_Indx, i_rows, i_cols);
	cout << endl;

	ar_Isrt_Indx = insert_row(ar_Isrt_Indx, i_rows, i_cols,xArr,xIndex);
	Print(ar_Isrt_Indx, i_rows, i_cols);
	cout << endl;

	for (int i = 0; i < i_rows; i++)
	{
		delete[] ar_Isrt_Indx[i];
	}
	delete[] ar_Isrt_Indx;
}

int** insert_row(int** arrMtrx, int& rows, int& cols, int* ar_row, int index)
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

			buffer[i][j] = arrMtrx[i][j];
		}
	}
	
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			if (index <= i) buffer[i + 1][j] = arrMtrx[i][j];
		}
	}
	
	for(int j=0;j<cols;j++)
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

void FillRand(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			arr[i][j] = rand() % 100;
		}
	}
}
void Print(int** arr, int rows, int cols)
{
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			cout << arr[i][j] << "\t"; //обращение к элементам через оператор индексирования
		}
		cout<<endl;
	}
}