#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long n;
vector<long long> t;
vector<long long> a(n);

void build(int v, int tl, int tr) {
    if (tl == tr)
        t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build (v*2, tl, tm);
        build (v*2+1, tm+1, tr);
        t[v] = t[v*2] + t[v*2+1];
    }
}

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

int main() {
    long long k;
    cin >> n >> k;
    t.resize(4*n, 0);

    for (int i = 0; i < k; i++) {
        char d;
        long long x, y;
        cin >> d >> x >> y;
        if (d == 'A') {
            x--;
            update(1, 0, n-1, x, y);
        }
        if (d == 'Q') {
            x--;
            y--;
            cout << sum(1, 0, n-1, x, y) << endl;
        }
    }

    return 0;
}