#include <iostream>
#include <vector>
#include <string>

using namespace std;
const int INF = 1000000000;

int main() {
    int n, s, f;
    cin >> n >> s >> f;
    s--;
    f--;
    vector < vector < pair<int,int> > > g (n);
    for (int i =0; i < n; i++) {
        for (int j =0; j < n; j++) {
            int x;
            cin >> x;
            if (x != -1)
                g[i].push_back({j, x});
        }
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

    cout << (d[f] != INF ? d[f] : -1);
    return 0;
}