#include <iostream>
#include <vector>
#include <algorithm>  // Dùng cho hàm max()

using namespace std;

void enter(int& n, int& W, vector<pair<int, int>>& items) {
    cout << "nhap vao so luong do vat va tong trong luong co the chua duoc cua balo";
    cin >> n >> W;
    items.resize(n + 1);  // Khởi tạo kích thước vector.

     /*Nhập dữ liệu các món đồ */
    cout << "nhap vao trong luong va gia tri cua do vat";
    for (int i = 1; i <= n; ++i) {
        cin >> items[i].first >> items[i].second;  // Trọng lượng và giá trị.
    }
}

// Truy vết các món đồ được chọn.
void trace_back(int n, int W, vector<vector<int>>& dp, vector<pair<int, int>>& items) {
    vector<int> picked_items;

    while (n > 0) {
        if (dp[n][W] == dp[n - 1][W]) {
            --n;
        }
        else {
            picked_items.push_back(n);  // Lưu lại món đồ được chọn.
            W -= items[n].first;  // Giảm tổng trọng lượng.
            --n;
        }
    }

    // In ra các món đồ đã chọn (theo thứ tự ngược).
    for (int i = picked_items.size() - 1; i >= 0; --i) {
        cout << picked_items[i] << ' ';
    }
    cout << endl;
}

// Giải bài toán bằng Quy hoạch động.
void solution(int n, int W, vector<pair<int, int>>& items) {
    vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));  // Bảng lưu trữ kết quả.

    // Tính toán bảng dp.
    for (int i = 1; i <= n; ++i) {
        for (int j = 0; j <= W; ++j) {
            dp[i][j] = dp[i - 1][j];  // Không chọn món đồ thứ i.

            if (j >= items[i].first) {  // Nếu đủ sức chứa để chọn món đồ i.
                dp[i][j] = max(dp[i][j], dp[i - 1][j - items[i].first] + items[i].second);
            }
        }
    }

    // In ra giá trị lớn nhất có thể lấy được.
    cout << dp[n][W] << endl;

    // Truy vết lại các món đồ đã chọn.
    trace_back(n, W, dp, items);
}

int main() {
    int n, W;
    vector<pair<int, int>> items;

    // Nhập dữ liệu đầu vào.
    enter(n, W, items);

    // Giải bài toán và in kết quả.
    solution(n, W, items);

    return 0;
}
