#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
vector<int> t;
vector<int> a;

void build(int v, int tl, int tr) {
    if (tl == tr)
        t[v] = tl;
    else {
        int tm = (tl + tr) / 2;
        build (v*2, tl, tm);
        build (v*2+1, tm+1, tr);
        t[v] = a[t[v*2]] > a[t[v*2+1]] ? t[v*2] : t[v*2+1];
    }
}

int sum (int v, int tl, int tr, int l, int r) {
    if (l > r)
        return -1;
    if (l == tl && r == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    int s1 = sum (v*2, tl, tm, l, min(r,tm));
    int s2 = sum (v*2+1, tm+1, tr, max(l,tm+1), r);
    if (s1 == -1) {
        return s2;
    }
    if (s2 == -1) {
        return s1;
    }
    if (a[s1] > a[s2]) {
        return s1;
    } else {
        return s2;
    }
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
    int k;
    int l, r;
    cin >> n;
    t.resize(4*n, 0);
    a.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    build(1, 0, n-1);

    cin >> k;

    for (int i = 0; i < k; i++) {
        cin >> l >> r;
        l--;
        r--;
        auto s = sum(1, 0, n-1, l, r);
        cout << a[s] << " " << s + 1 << endl;
    }

    return 0;
}