#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;

const int INF = 1000000;

struct edge {
    int a, b, cost;
};

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> f(n);
    for (int i = 0; i < n; i++) {
        cin >> f[i];
    }

    vector<edge> e;
    for (int i = 0; i < m; i++) {
        int o, p;
        cin >> o >> p;
        edge e1 = {o - 1, p -1};
        edge e2 = {p -1, o - 1};
        e.push_back(e1);
        e.push_back(e2);
    }

    vector<int> d (n, INF);
    d[0] = 0;
    vector<int> p (n, -1);
    for (;;) {
        bool any = false;
        for (int j=0; j<e.size(); ++j)
            if (d[e[j].a] < INF)
                if (d[e[j].b] > d[e[j].a] + (f[e[j].a] == f[e[j].b] ? 0 : 1)) {
                    d[e[j].b] = d[e[j].a] + (f[e[j].a] == f[e[j].b] ? 0 : 1);
                    p[e[j].b] = e[j].a;
                    any = true;
                }
        if (!any)  break;
    }

    if (d[n-1] == INF)
        cout << "impossible";
    else {
        vector<int> path;
        for (int cur=n-1; cur!=-1; cur=p[cur])
            path.push_back (cur);
        reverse (path.begin(), path.end());

        cout << d[n-1] << " " << path.size() << endl;
        for (size_t i=0; i<path.size(); ++i)
            cout << path[i] + 1 << ' ';
    }

    return 0;
}