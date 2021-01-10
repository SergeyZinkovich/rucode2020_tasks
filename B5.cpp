#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

const int MULT = 1000228;

int n, m;
vector<vector<int>>  f, down_, right_, up_, left_;
vector<vector<vector<int>>>  sparse_row, sparse_col;
int logs[MULT];

inline int ask_row(int i, int l, int r) {
    int level = logs[r - l +1];
    return max(sparse_row[i][level][l], sparse_row[i][level][r - (1 << level) + 1]);
}

inline int ask_col(int i, int l, int r) {
    int level = logs[r - l +1];
    return max(sparse_col[i][level][l], sparse_col[i][level][r - (1 << level) + 1]);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    logs[1] = 0;
    for (int i = 2; i < MULT; i++) {
        logs[i] = logs[i / 2] + 1;
    }
    cin >> n >> m;

    f.resize(n, vector<int>(m));
    down_.resize(n, vector<int>(m));
    up_.resize(n, vector<int>(m));
    left_.resize(n, vector<int>(m));
    right_.resize(n, vector<int>(m));
    sparse_row.resize(n, vector<vector<int>>(logs[m] + 2, vector<int>(m)));
    sparse_col.resize(m, vector<vector<int>>(logs[n] + 2, vector<int>(n)));
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        for (int j = 0; j < m; j++) {
            f[i][j] = (s[j] == '1' ? 1 : 0);
        }
    }
    for (int i = n - 1; i > -1; i--) {
        for (int j = 0; j < m; j++) {
            if (!f[i][j]) {
                down_[i][j] = 0;
            } else {
                down_[i][j] = 1;
                if (i < n - 1) {
                    down_[i][j] += down_[i + 1][j];
                }
            }
        }
    }
    for (int j = m - 1; j > -1; j--) {
        for (int i = 0; i < n; i++) {
            if (!f[i][j]) {
                right_[i][j] = 0;
            } else {
                right_[i][j] = 1;
                if (j < m - 1) {
                    right_[i][j] += right_[i][j + 1];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!f[i][j]) {
                up_[i][j] = 0;
            } else {
                up_[i][j] = 1;
                if (i > 0) {
                    up_[i][j] += up_[i - 1][j];
                }
            }
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            if (!f[i][j]) {
                left_[i][j] = 0;
            } else {
                left_[i][j] = 1;
                if (j > 0) {
                    left_[i][j] += left_[i][j - 1];
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            sparse_row[i][0][j] = down_[i][j];
        }
        for (int level = 1; (1 << level) <= m; level++){
            for (int beg = 0; beg <= m - (1 << level); beg++) {
                sparse_row[i][level][beg] = max(sparse_row[i][level - 1][beg], sparse_row[i][level - 1][beg + (1 << (level - 1))]);
            }
        }
    }
    for (int j = 0; j < m; j++) {
        for (int i = 0; i < n; i++) {
            sparse_col[j][0][i] = right_[i][j];
        }
        for (int level = 1; (1 << level) <= n; level++){
            for (int beg = 0; beg <= n - (1 << level); beg++) {
                sparse_col[j][level][beg] = max(sparse_col[j][level - 1][beg], sparse_col[j][level - 1][beg + (1 << (level - 1))]);
            }
        }
    }

    int Q;
    cin >> Q;
    vector<int> ans;
    ans.reserve(Q);
    for (int i = 0; i < Q; i++) {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;
        x2--;
        y2--;
        int r1 = min(y1 + right_[x1][y1] - 1, y2);
        int l2 = max(y2 - left_[x2][y2] + 1, y1);
        if (r1 >= l2 && ask_row(x1, l2, r1) >= x2 - x1 + 1) {
            ans.push_back(1);
            continue;
        }
        r1 = min(x1 + down_[x1][y1] - 1, x2);
        l2 = max(x2 - up_[x2][y2] + 1, x1);
        if (r1 >= l2 && ask_col(y1, l2, r1) >= y2 - y1 + 1) {
            ans.push_back(1);
            continue;
        }
        ans.push_back(0);
    }

    for (int i = 0; i < (int)ans.size(); i++) {
        cout << ans[i] << ' ';
    }


    return 0;
}