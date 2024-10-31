#include <iostream>
using namespace std;
void print() {
    cout << "khong the thuc hien duoc" << endl;
}
int BuyRiceDay(int A, int B, int C, int D) {
    int current_rice = 0;
    int day = 0;
    int total_rice_needed = B * C;
    int weekday = D - 1;
    while (current_rice < total_rice_needed) {
        if (weekday != 6) {
            current_rice += A;
        }
        if (day > B && current_rice < total_rice_needed) {
            print();
            return -1;
        }
        if (current_rice < B)
        {
            print();
            return -1;
        }
        weekday = (weekday + 1) % 7;
        day++;
        current_rice = 0;
    }
    return day;
}
int main() {
    cout << "Nhap vao so luong gao nguoi do co the mua trong 1 ngay: ";
    int A; cin >> A;
    cout << "Nhap vao so luong ngay ma gia dinh do can gao: ";
    int B; cin >> B;
    cout << "Nhap vao so luong gao moi ngay gia dinh do can: ";
    int C; cin >> C;
    cout << "Nhap vao ngay gia su trong tuan (1=Thu Hai, 7=Chu Nhat): ";
    int D; cin >> D;
    int result = BuyRiceDay(A, B, C, D);
    if (result != -1) {
        cout << "So ngay it nhat de mua gao la: " << result << endl;
    }
    
}
