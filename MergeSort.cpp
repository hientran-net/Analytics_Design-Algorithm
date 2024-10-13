#include <iostream>
#include <vector>
using namespace std;


//Trộn hai mảng con : dãy 1 [l, m], dãy 2 :[m + 1, r]
void merge(int a[], int left, int middle, int right)
{
	vector<int> firstArray(a + left, a + middle + 1);
	vector<int> secondArray(a + middle + 1, a + right + 1);

	int i = 0, j = 0;

	while (i < firstArray.size() && j < secondArray.size())
	{
		if (firstArray[i] <= secondArray[j])
		{
			a[left] = firstArray[i];
			++left, ++i;
		}
		else
		{
			a[left] = secondArray[j];
			++left, ++j;
		}
	}

	while (i < firstArray.size())
	{
		a[left] = firstArray[i];
		++left, ++i;
	}
	
	while (j < secondArray.size())
	{
		a[left] = secondArray[j];
		++left, ++j;
	}
}

void mergeSort(int a[], int left, int right)
{
	if (left >= right)
		return;

	int middle = (left + right) / 2;
	mergeSort(a, left, middle);
	mergeSort(a, middle + 1, right);
	merge(a, left, middle, right);
}

void printArray(int a[], int arrayLenght)
{
	for (int i = 0; i < arrayLenght; i++)
	{
		cout << a[i] << " ";
	}
}

int main() 
{
	int a[] = { 11, 10, 19, 6, 20, 25, 78, 8, 7, 21, 1, 2 };

	// độ dài mảng a:
	int n = sizeof(a) / sizeof(int);

	mergeSort(a, 0, n - 1);

	// in ra mang:
	printArray(a, n);
	
	return 0;
}