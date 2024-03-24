//Pointers
#include<iostream>
using namespace std;
#define POINTERS_BASICS

void main() {

	setlocale(LC_ALL, "");

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

}