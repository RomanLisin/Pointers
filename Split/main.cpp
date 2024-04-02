#include<iostream>
using std::cout;
using std::cin;
using std::endl;

void FillRand(int i_arr[],const int a_size);
void Print( const int i_arr[],const int a_size);

int* PushBack(int i_arr[], int& n,const int value);


void main()
{
	setlocale(LC_ALL, "");
	int arr_size = 10;
	int even_size = 0;
	int odd_size=0;
	
	int* arr = new int[arr_size];

	FillRand(arr,arr_size);
	cout << "Source array:\t"; Print(arr, arr_size);
	

	for (int i = 0; i < arr_size; i++)
	{
		(arr[i] & 1 ? odd_size++ : even_size++); 
	}

	int* even = new int[even_size];
	int* odd = new int[odd_size];

	for (int i = 0,k=0,j=0; i < arr_size; i++)
	{
		((arr[i] & 1) ?*(odd+ j++) :*(even+ k++)) =*(arr+i);
	}
	delete[] arr;

	 
	cout << "\n\n\nArray of " << even_size << " even elements:\t"; Print(even, even_size);
	

	cout << "\nArray of " << odd_size << " odd elements:\t"; Print(odd, odd_size);
	

	int pushValue;
	cout << "\nInput add value:  "; cin >> pushValue;
	odd=PushBack(odd, odd_size, pushValue);
	cout << "\nArray with add to back element:\t\t"; Print(odd, odd_size);
	cout << endl;


	delete[] even;
	delete[] odd;
	
}
void FillRand(int even[],const int a_size)
{
	for (int i = 0; i < a_size; i++)
	{
		*(even + i) =50+ rand() % 50;

	}
}
void Print(const int even[], const int a_size)
{
	for (int i=0; i<a_size; i++)
	{
		cout << *(even+i) << "\t";
	}

}

int* PushBack(int i_arr[], int& n,const int value) // m value of add element 
{	
	int* buffer = new int[n+1];
	for (int i = 0; i < n; i++)
	{
		buffer[i] = i_arr[i];
	}
	delete[] i_arr;
	i_arr=buffer;
	i_arr[n] = value;
	n++;
	return i_arr;
}
