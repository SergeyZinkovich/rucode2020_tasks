#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long n;
vector<int> t;

long long sum (int v, int tl, int tr, int l, int r) {
    if (l > r)
        return 0;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    return sum (v*2, tl, tm, l, min(r,tm))
           + sum (v*2+1, tm+1, tr, max(l,tm+1), r);
}

void update (int v, int tl, int tr, int pos, int new_val) {
    if (tl == tr)
        t[v] = new_val;
    else {
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            update (v*2, tl, tm, pos, new_val);
        else
            update (v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

long long a1, b1;
unsigned int cur = 0;
unsigned int nextRand24() {
    cur = cur * a1 + b1;
    return cur >> 8;
}

int main() {
    long long m;
    cin >> n >> m >> a1 >> b1;
    t.resize(4*m, 0);

    long long ans = 0;
    for (int i = 0; i < n; i++) {
        long long x = nextRand24() % m;
        ans += sum(1, 0, m-1, x+1, m-1);
        update(1, 0, m-1, x, sum(1, 0, m-1, x, x)+1);
    }

    cout << ans;

    return 0;
}