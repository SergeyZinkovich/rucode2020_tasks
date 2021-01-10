#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;
const int INF = 1000000000;

int main() {
    int n, m, s, f;
    cin >> n >> m >> s >> f;
    s--;
    f--;
    vector < vector < pair<int,int> > > g (n);
    for (int i =0; i < m; i++) {
        int x, y, z;
        cin >> x >> y >> z;
        x--;
        y--;
        g[x].push_back({y, z});
        g[y].push_back({x, z});
    }

    vector<int> d (n, INF),  p (n);
    d[s] = 0;
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
                    len = g[v][j].second;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                p[to] = v;
            }
        }
    }

    cout << (d[f] != INF ? d[f] : -1) << endl;

    vector<int> path;
    for (int v=f; v!=s; v=p[v])
        path.push_back (v);
    path.push_back (s);
    reverse (path.begin(), path.end());

    for (int i = 0; i < (int)path.size(); i++) {
        cout << path[i] + 1 << ' ';
    }

    return 0;
}