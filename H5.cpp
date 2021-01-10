#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

long long n;
vector<long long> t;
vector<long long> a;

void build(long long v, long long tl, long long tr) {
    if (tl == tr) {
        t[v] = a[tl];
        if (tl % 2 == 0) {
            t[v] *= -1;
        }
    }
    else {
        long long tm = (tl + tr) / 2;
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

void update (int v, long long tl, long long tr, long long pos, long long new_val) {
    if (tl == tr)
        t[v] = new_val;
    else {
        long long tm = (tl + tr) / 2;
        if (pos <= tm)
            update (v*2, tl, tm, pos, new_val);
        else
            update (v*2+1, tm+1, tr, pos, new_val);
        t[v] = t[v*2] + t[v*2+1];
    }
}

int main() {
    long long k;
    cin >> n;
    t.resize(4*n, 0);
    a.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    build(1,0,n-1);

    cin >> k;

    for (int i = 0; i < k; i++) {
        int d;
        long long x, y;
        cin >> d >> x >> y;
        if (d == 0) {
            x--;
            if (x % 2 == 0) {
                y *= -1;
            }
            update(1, 0, n-1, x, y);
        }
        if (d == 1) {
            x--;
            y--;
            long long s = sum(1, 0, n-1, x, y);
            if (x % 2 == 0) {
                s *= -1;
            }
            cout << s << endl;
        }
    }

    return 0;
}