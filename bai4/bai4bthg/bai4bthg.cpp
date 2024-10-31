#include <iostream>
#include <vector>
#include <algorithm>  
using namespace std;
int MaxValue(int n, int s, vector<int>& w, vector<int>& v, vector<vector<int>>& dp) {
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= s; ++j) {
            dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= s; ++j) {
            dp[i][j] = dp[i - 1][j];

            if (j >= w[i]) {
                dp[i][j] = max(dp[i][j], dp[i - 1][j - w[i]] + v[i]);
            }
        }
    }
    return dp[n][s];
}
int main() {
    cout << "Nhap vao so luong do vat va trong luong cua balo: ";
    int n, s;
    cin >> n >> s;
    vector<int> w(n + 1), v(n + 1);
    cout << "Nhap vao khoi luong va gia tri cua cac vat pham (theo thu tu):" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << "Do vat " << i << " (khoi luong, gia tri): ";
        cin >> w[i] >> v[i];  
    }
    vector<vector<int>> dp(n + 1, vector<int>(s + 1, 0));
    cout << "Gia tri lon nhat cua cac vat pham co the bo vao balo la: "
        << MaxValue(n, s, w, v, dp) << endl;
    return 0;
}
