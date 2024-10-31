#include <iostream>
#include <vector>
#include <algorithm> 
#include <string>
using namespace std;

int main() {
    vector<int> A = { 2, 1, 4, 3, 5 }; 
    string num1 = "", num2 = ""; 

    sort(A.begin(), A.end());

    
    for (size_t i = 0; i < A.size(); i++) {
       
        if (num1.size() <= num2.size()) {
            num1 += to_string(A[i]); 
        }
        else {
            num2 += to_string(A[i]);
        }
    }

    
    int totalSum = stoi(num1) + stoi(num2);

    cout << "Hai số nhỏ nhất là: " << num1 << " và " << num2 << endl;
    cout << "Tổng nhỏ nhất là: " << totalSum << endl;

    return 0;
}
