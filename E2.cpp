#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    if (n == 1) {
        cout << 1;
        return 0;
    }
    vector<int> a(2 * n);
    vector<int> f(2 * n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        a[i+n] = a[n-i-1];
    }
    f[0] = 0;
    int k = 0;
    for (int i = 1; i < 2 * n; i++) {
        while ((k > 0) && (a[k] != a[i]))
            k = f[k-1];
        if (a[k] == a[i])
            k++;
        f[i] = k;
    }
    k = f[2*n-1];
    while (k > n) {
        k = f[k-1];
    }
    while (k > 0) {
        if (k % 2 == 0)
            cout << n-((int)k / 2) << ' ';
        k = f[k-1];
    }
    cout << n;
}