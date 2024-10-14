#include <iostream>
#include <vector>
#include <cstdlib> 
#include <ctime> 

using namespace std;

bool isPrime(int num) {
	if (num <= 1) return false;
	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void lastPrimeNumber(const vector<int>& arr, int left, int right, int result[]) {
	if (left > right) {
		result[0] = -1;
		result[1] = -1;
		return;
	}

	if (isPrime(arr[right])) {
		result[0] = right;
		result[1] = arr[right];
		return;
	}

	lastPrimeNumber(arr, left, right - 1, result);
}

void firstPositiveNumber(vector<int>& arr, int left, int right, int result[]) {
	if (left > right) {
		result[0] = -1;
		result[1] = -1;
		return;
	}

	if (arr[left] > 0) {
		result[0] = left;
		result[1] = arr[left];
		return;
	}

	firstPositiveNumber(arr, left + 1, right, result);
}

void printArray(vector<int> a, int sizeOfArray)
{
	for (int i = 0; i < sizeOfArray; i++)
	{
		cout << a[i] << " ";
	}
}

int main()
{
	int n;
	cout << "Enter number of element in array: ";
	cin >> n;

	int firstPositiveNumberResult[2];
	int lastPrimeNumberResult[2];
	vector<int> a;

	srand(time(NULL));

	for (int i = 0; i < n; i++)
	{
		// chon dau ngau nhien
		int sign = (rand() % 2) == 0 ? -1 : 1;
		a.push_back(sign * (rand() % 100));
	}

	cout << "Random array: ";
	printArray(a, n);
	cout << "\n";

	firstPositiveNumber(a, 0, n - 1, firstPositiveNumberResult);
	if (firstPositiveNumberResult[0] != -1) {
		cout << "\nFirst positive number: " << firstPositiveNumberResult[1] << " at index: " << firstPositiveNumberResult[0] << endl;
	}
	else {
		cout << "No positive number found." << endl;
	}

	lastPrimeNumber(a, 0, n - 1, lastPrimeNumberResult);
	if (lastPrimeNumberResult[0] != -1) {
		cout << "\nLast prime number: " << lastPrimeNumberResult[1] << " at index: " << lastPrimeNumberResult[0] << endl;
	}
	else {
		cout << "No prime number found." << endl;
	}
}