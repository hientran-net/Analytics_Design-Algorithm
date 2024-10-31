#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Hàm tìm độ dài chuỗi con chung dài nhất
int longestCommonSubsequence(string str1, string str2) {
    int m = str1.length();
    int n = str2.length();

    // Tạo bảng dp có kích thước (m+1) x (n+1)
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    // Điền bảng dp
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (str1[i - 1] == str2[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1; // Nếu trùng ký tự
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]); // Chọn giá trị lớn hơn
            }
        }
    }

    // Độ dài của chuỗi con chung dài nhất
    return dp[m][n];
}

int main() {
    string str1, str2;
    str1 = "ABCDEF";
    str2 = "AXBCYDGH";

    int length = longestCommonSubsequence(str1, str2);
    cout << "Do dai chuoi con chung dai nhat: " << length << endl;

    return 0;
}
