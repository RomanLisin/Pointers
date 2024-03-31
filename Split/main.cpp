#include<iostream>
using std::cout;
using std::cin;
using std::endl;

void FillRand(int i_arr[],const int n);
void Print( const int i_arr[],const int n);
void DelElement(int i_arr[], int* n, int m);
void PushBack(int i_arr[], int* n, int m);

void main()
{
	setlocale(LC_ALL, "");
	int n = 10;
	int* even = new int[n];
	int s=10;
	int* odd = new int[s];

	FillRand(even,n);
	cout << "even  "; Print(even, n);
	cout << endl;

	//FillRand(odd, s);
	for (int i=0;i<s;i++)
	{
		*(odd + i) = 0;
	}
	cout << "odd  "; Print(odd, s);
	cout << endl;

	for (int i = 0; i < n; i++)
	{
	int k = 0;
		
		if ((even[i] & 1)==0)        // check number is even or odd
		{

			// if odd
			// record to other array
			// push_back(even, &n); add element to the end of the array2, 
			++k;
			DelElement(even, &n, k);// delete element from array1, k number of element which delete (erase)
			cout << "even  "; Print(even, n); cout << endl;
			//PushBack(odd, &s, k); // push the value of i-element to the last element of array
			           
		}
		else
		{
			odd[i] = even[i];
			
		}
	}
	cout << endl; 
	Print(even, n);
	cout << endl;

	Print(odd, s);
	cout << endl;

	for (int i = 0; i < n; i++)
	{
		cout << i << " " << (even + i) << "\n";
	}
		cout << endl;


	for (int i = 0; i < n; i++)
	{
		cout << i << " " << (odd + i) << "\n";
	}
	delete[] even;
	delete[] odd;
}
void FillRand(int even[],const int n)
{
	for (int i = 0; i < n; i++)
	{
		*(even + i) =50+ rand() % 50;

	}
}
void Print(const int even[], const int n)
{
	for (int i=0; i<n; i++)
	{
		cout << *(even+i) << "\t";
	}

}

void DelElement(int *i_arr, int* n, int m)
{
	for (int i = m-1; i < *n-1; i++)
	{
		*(i_arr + i) = *(i_arr + i + 1);
	--*n;
	cout << "delElem  "; Print(i_arr, *n); cout << endl;
	}
}
void PushBack(int i_arr[], int* n,int m) // m value of add element 
{	
	i_arr +1;  // add element
	*(i_arr + *n+1) = m;
}

