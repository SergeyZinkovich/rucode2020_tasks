#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int INF = 1000000000;
vector<vector<pair<int, pair<int, int>>>> g;

bool check(int n, int l) {
    vector<int> d(n, INF), p(n);
    d[0] = 0;
    vector<char> u(n);
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; ++j)
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        if (d[v] == INF)
            break;
        u[v] = true;

        for (size_t j = 0; j < g[v].size(); ++j) {
            int to = g[v][j].first,
                    len = g[v][j].second.first;
            if (l > g[v][j].second.second) { continue; }
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }
    return (d[n-1] <= 1440 ? 1 : 0);
}

int main() {
    int n, m;
    cin >> n;
    g.resize(n);

    cin >> m;
    for (int i =0; i < m; i++) {
        int w, x, y, z;
        cin >> x >> y >> w >> z;
        x--;
        y--;
        g[x].push_back({y, {w, z}});
        g[y].push_back({x, {w, z}});
    }

    int left = 0, right = 1003000000;
    int l;

    while (left < right-1) {
        l = (right + left) / 2;
        if (!check(n, l)) {
            right = l;
        } else {
            left = l;
        }
    }

    int k;
    if (check(n, right)) {
        k = right;
    } else {
        k = left;
    }

    if (k < 3000000 || !check(n, k)) {
        cout << 0;
    } else {
        cout << (int) (k - 3000000) / 100;
    }

    return 0;
}