#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <deque>

#include <chrono>
using namespace std::chrono;

using namespace std;

int n, x, y, a0, m, z, t, b0;
int a[10000000] ;
int b[20000001];
long long p[10000000];

int main() {
    cin >> n >> x >> y >> a0;
    cin >> m >> z >> t >> b0;

    p[0] = a0;
    a[0] = a0;
    for (long long i = 1; i < n; i++) {
        a[i] = (x * a[i-1] + y) & 65535;
        if (a[i] < 0) {
            a[i] = 65536 + a[i];
        }

        p[i] = p[i-1] + a[i];
    }
    long long G = 2 * m + 1;
    b[0] = b0;

    for (long long i = 1; i < G; i++) {
        b[i] = (z * b[i - 1] + t) & 1073741823;
        if (b[i] < 0) {
            b[i] = 1073741824 + b[i];
        }
    }
    long long s = 0;
    for (long long i = 0; i < m; i++) {
        auto h = 2 * i;
        auto g = b[h] % n;
        auto k = b[h+1] % n;
        long long l = min(g , k);
        long long r = max(g, k);
        s += p[r] - (l > 0 ? p[l-1]: 0);
    }

    cout << s;

    return 0;
}