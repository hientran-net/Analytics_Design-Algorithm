#include <iostream>

using namespace std;

int findMin(int arr[], int left, int right) 
{

    if (left == right) 
        return arr[left];
        
    int mid = (left + right) / 2;

    int minLeft = findMin(arr, left, mid);

    int minRight = findMin(arr, mid + 1, right);

    return min(minLeft, minRight);
}

int main() {
    int a[] = { 15, 10, 9, 5, 20, 78, 8, 6, 21, 1 };
    int size = sizeof(a) / sizeof(int);
    int minValue = findMin(a, 0, size - 1);

    cout << "Minimum value in the array is: " << minValue << endl;

    return 0;
}
