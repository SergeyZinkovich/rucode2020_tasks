#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int INF = 1000000000;

int main() {
    int n, m, v1, v2;
    cin >> n >> v1 >> v2;
    v1--;
    v2--;
    vector<vector<pair<int, pair<int, int>>>> g(n);

    cin >> m;
    for (int i =0; i < m; i++) {
        int w, x, y, z;
        cin >> w >> x >> y >> z;
        w--;
        y--;
        g[w].push_back({y, {x, z}});
    }

    vector<int> d (n, INF),  p (n);
    d[v1] = 0;
    vector<char> u (n);
    for (int i=0; i<n; ++i) {
        int v = -1;
        for (int j=0; j<n; ++j)
            if (!u[j] && (v == -1 || d[j] < d[v]))
                v = j;
        if (d[v] == INF)
            break;
        u[v] = true;

        for (size_t j=0; j<g[v].size(); ++j) {
            int to = g[v][j].first,
                    len = g[v][j].second.second;
            if (d[v] > g[v][j].second.first) { continue; }
            if (len < d[to]) {
                d[to] = len;
                p[to] = v;
            }
        }
    }

    cout << (d[v2] != INF ? d[v2] : -1) << endl;

    return 0;
}