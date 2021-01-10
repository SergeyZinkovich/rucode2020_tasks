#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int INF = 1000000000;

int main() {
    int n, m;
    cin >> n;
    vector<int> f(n);
    vector < vector < pair<int,int> > > g (n);
    for (int i =0; i < n; i++) {
        cin >> f[i];
    }

    cin >> m;
    for (int i =0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        x--;
        y--;
        g[x].push_back({y, 1});
        g[y].push_back({x, 1});
    }

    vector<int> d (n, INF),  p (n);
    d[0] = 0;
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
                    len = f[v];
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }

    cout << (d[n-1] != INF ? d[n-1] : -1) << endl;

    return 0;
}