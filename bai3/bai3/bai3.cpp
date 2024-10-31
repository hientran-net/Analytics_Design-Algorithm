#include <iostream>
#include <vector>
using namespace std;

void DoiTien(long long n) {
    vector<long> LooseChanges = { 500000, 200000, 100000, 50000, 20000, 10000, 5000, 2000, 1000 };

    for (long mg : LooseChanges) {
        if (n >= mg) {
            long Count = n / mg;
            cout << Count << " to " << mg << " VND\n";
            n %= mg;  
        }
        if (n == 0)  
            break;
    }
}

int main() {
    long long n;
    cout << "Nhap vao so tien: ";
    cin >> n;
    cout << "\nSo tien sau khi đoi là:\n";
    DoiTien(n);
    return 0;
}
