#include <iostream>
using namespace std;

void swap(int& a, int& b)
{
	int temp = a;
	a = b; 
	b = temp;
}

int partition(int a[], int left, int right)
{
	int j = left - 1;
	int pivot = a[right];

	for (int i = left; i < right; i++)
	{
		if (a[i] <= pivot)
		{
			++j;
			swap(a[i], a[j]);
		}
	}
	++j;
	swap(a[right], a[j]);
	
	return j;
}

void quickSort(int a[], int left, int right)
{
	if (left < right)
	{
		int p = partition(a, left, right);
		quickSort(a, left, p - 1);
		quickSort(a, p + 1, right);
	}
}

void printArray(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << a[i] << " ";
	}
}

int main()
{
	int a[] = { 15, 10, 9, 5, 20, 78, 8, 6, 21, 1 };

	int sizeOfA = sizeof(a) / sizeof(int);
	int left = 0;
	int right = sizeof(a) / sizeof(int) - 1;


	quickSort(a, left, right);
	printArray(a, sizeOfA);

	return 0;
}