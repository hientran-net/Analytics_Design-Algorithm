#include <iostream>
#include <vector>
using namespace std;

int countEqualK(vector<int>& arr, int k, int left, int right) {
    if (left > right) return 0;

    if (left == right) {
        return arr[left] == k ? 1 : 0;
    }

    int mid = left + (right - left) / 2;

    return countEqualK(arr, k, left, mid) + countEqualK(arr, k, mid + 1, right);
}

int countBetweenXY(vector<int>& arr, int x, int y, int left, int right) {
    if (left > right) return 0;

    if (left == right) {
        return (arr[left] > x && arr[left] < y) ? 1 : 0;
    }

    int mid = left + (right - left) / 2;

    return countBetweenXY(arr, x, y, left, mid) + countBetweenXY(arr, x, y, mid + 1, right);
}

int main() {
    int n, k, x, y;

    cout << "Nhap so luong phan tu cua mang: ";
    cin >> n;

    vector<int> arr(n);
    cout << "Nhap cac phan tu cua mang: ";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    cout << "Nhap gia tri k: ";
    cin >> k;

    int countK = countEqualK(arr, k, 0, n - 1);
    cout << "So luong phan tu bang " << k << " la: " << countK << endl;

    cout << "Nhap gia tri x va y (x < y): ";
    cin >> x >> y;

    int countXY = countBetweenXY(arr, x, y, 0, n - 1);
    cout << "So luong phan tu lon hon " << x << " va nho hon " << y << " la: " << countXY << endl;

    return 0;
}
