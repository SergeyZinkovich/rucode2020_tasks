#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>
#include <queue>

using namespace std;

int n, cou = 0;
vector<int> g[100];
bool used[100];
vector<int> comp;

void dfs (int v) {
    used[v] = true;
    comp.push_back (v);
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (! used[to])
            dfs (to);
    }
}

int find_comps() {
    for (int i=0; i<n; ++i)
        used[i] = false;
    for (int i=0; i<n; ++i)
        if (! used[i]) {
            comp.clear();
            dfs (i);

            cou++;
        }
    return cou;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int w;
        cin >> w;
        w--;
        g[w].push_back(i);
        g[i].push_back(w);
    }

    cout << find_comps();

    return 0;
}