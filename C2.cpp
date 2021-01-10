#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {
    string s;
    cin >> s;

    const long long p = 31;
    const long long m = 1000000007;
    int n = (long long)s.length();
    vector<long long> p_pow (n+1);
    vector<long long> h (n+1);
    p_pow[0] = 1;
    for (int i = 0; i < n; ++i) {
        int cur = int(s[i]) - 'a' + 1;
        h[i + 1] = (h[i] * p + cur) % m;
        p_pow[i + 1] = p_pow[i] * p % m;
    }

    int k;
    cin >> k;
    for (int i = 0; i < k; i++) {
        int z, x, c, v;
        cin >> z >> x >> c >> v;
//        z--;
//        x--;
//        c--;
//        v--;
        long long p1 = (m + h[x] - h[z - 1] * p_pow[x - z + 1] % m) % m;
        long long p2 = (m + h[v] - h[c - 1] * p_pow[v - c + 1] % m) % m;
        if (p1 == p2) {
            cout << "Yes" << endl;
        } else {
            cout << "No" << endl;
        }
    }

    return 0;
}