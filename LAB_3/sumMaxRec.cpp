#include <iostream>
#include <vector>
using namespace std;

int maxSumRec(vector<int>& arr, int n) {

    if (n <= 0)  return 0;
    if (n == 1)  return arr[0];

    int pick = arr[n - 1] + maxSumRec(arr, n - 2);
    int notPick = maxSumRec(arr, n - 1);

    return max(pick, notPick);
}

int main() {
    //= { 6, 7, 1, 3, 8, 2 };
    int n;
    cout << "enter size of array: ";
    cin >> n;
    vector<int> arr(n);

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    cout << maxSumRec(arr, n);
    return 0;
}