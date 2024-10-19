#include <iostream>
#include <vector>

using namespace std;

int LIS(vector<int> a, int n, vector<int> L)
{
	//duyệt qua từng phần tử đứng trước chỉ số i
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < i; j++)
		{
			if (a[i] > a[j])
			{
				L[i] = max(L[i], L[j] + 1);
			}
		}
	}

	//tìm phần tử lớn nhất là độ dài của chuỗi con tăng dài nhất trong mảng 
	int maxElement = L[0];
	for (int i = 0; i < L.size(); i++)
	{
		if (L[i] >= maxElement)
			maxElement = L[i];
	}

	//Trả về độ dài của chuỗi con tăng dài nhất
	return maxElement;
}

int main()
{
	int n;
	cout << "enter size of array: ";
	cin >> n;

	vector<int> a(n);

	for (int i = 0; i < n; i++)
		cin >> a[i];

	vector<int> L(n, 1);

	cout << LIS(a, n, L);


	return 0;
}