#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n), z(n), s(n);

    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }

    int c = 0;
    for (int i = 0; i < n; i++) {
        if (p[i] == 0) {
            s[i] = c;
            c++;
        } else {
            s[i] = s[p[i] -1];
        }
    }

    int l = 0, r = 0;
    for (int i=1; i<n; ++i) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i+z[i] < n && s[z[i]] == s[i+z[i]]) {
            ++z[i];
        }
        if (i+z[i]-1 > r) {
            l = i, r = i + z[i] - 1;
        }
    }
    z[0] = n;

    for(int i = 0; i < z.size(); i++) {
        cout << z[i] << " ";
    }

    return 0;
}