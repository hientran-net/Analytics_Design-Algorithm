#include <iostream>
#include <algorithm>
using namespace std;

int maxSum(int n, int a[105]) {
    int sum = 0;  
    for (int i = 1; i <= n; i++) { 
        sum = sum + (a[i] * i);
    }
    return sum;
}

int main() {
    int n, a[105];
    cout << "Nhap vao n: ";
    cin >> n;

    cout << "Nhap vao phan tu cua mang: ";
    for (int i = 1; i <= n; i++) {  
        cin >> a[i];
    }

    sort(a + 1, a + n + 1, greater<int>()); 

    cout << "Mang sau khi dieu chinh de co tong lon nhat la: " << endl;
    for (int i = 1; i <= n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    cout << "Tong lon nhat la: " << maxSum(n, a) << endl;
    return 0;
}
