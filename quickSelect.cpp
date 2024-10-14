#include <iostream>
#include <vector>
using namespace std;

void swap(int& a, int& b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}

int partition(vector<int>& a, int left, int right) {
    int pivot = a[right];
    int i = left;

    for (int j = left; j < right; j++) {
        if (a[j] > pivot) { 
            swap(a[i], a[j]);
            i++;
        }
    }
    swap(a[i], a[right]);
    return i;
}

int quickselect(vector<int>& a, int left, int right, int k) {
    if (left == right) {
        return a[left];
    }

    int pivotIndex = partition(a, left, right);
    if (k == pivotIndex) {
        return a[k];
    }
    else if (k < pivotIndex) {
        return quickselect(a, left, pivotIndex - 1, k);
    }
    else {
        return quickselect(a, pivotIndex + 1, right, k);
    }
}

int main() {
    vector<int> a = { 11, 7, 19, 6, 20, 25, 78, 8, 7, 21, 7, 2 };
    int k = 3;
    int n = a.size();

    int kthLargest = quickselect(a, 0, n - 1, n - k);

    cout << "Phan tu lon thu " << k << " trong mang la: " << kthLargest << endl;

    return 0;
}
