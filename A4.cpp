#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1000000;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> a(n, vector<int>(m));
    vector<vector<int>> d(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }
    int x1, y1, x2, y2;
    cin >> x1 >> y1 >> x2 >> y2;
    x1--;
    y1--;
    x2--;
    y2--;
    d[y1][x1] = 0;

    if (a[y1][x1] == 1 || a[y2][x2] == 1) {
        return -1;
    }

    vector<vector<char>> used(n, vector<char>(m));
    used[y1][x1] = true;
    queue<pair<int, int>> q;
    q.push({y1, x1});

    while (!q.empty()) {
        auto v = q.front();
        q.pop();
        if (v.first > 0 && !used[v.first-1][v.second] && a[v.first-1][v.second] != 1) {
            used[v.first-1][v.second] = true;
            q.push({v.first-1, v.second});
            d[v.first-1][v.second] = d[v.first][v.second] + 1;
        }
        if (v.first < n - 1 && !used[v.first+1][v.second] && a[v.first+1][v.second] != 1) {
            used[v.first+1][v.second] = true;
            q.push({v.first+1, v.second});
            d[v.first+1][v.second] = d[v.first][v.second] + 1;
        }
        if (v.second > 0 && !used[v.first][v.second-1] && a[v.first][v.second-1] != 1) {
            used[v.first][v.second-1] = true;
            q.push({v.first, v.second-1});
            d[v.first][v.second-1] = d[v.first][v.second] + 1;
        }
        if (v.second < m-1 && !used[v.first][v.second+1] && a[v.first][v.second+1] != 1) {
            used[v.first][v.second+1] = true;
            q.push({v.first, v.second+1});
            d[v.first][v.second+1] = d[v.first][v.second] + 1;
        }
    }

    if (used[y2][x2])
        cout << d[y2][x2];
    else
        cout << -1;

    return 0;
}