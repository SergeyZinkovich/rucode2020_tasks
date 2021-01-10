#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;
    int n = (int) s.length();
    int ans = 0, k = 0;

    for (int i = 0; i < (int) s.length(); i++) {
        k++;

        int l = 0, r = 0;
        vector<int> z (k, 0);
        int m = 0;
        for (int j = 1; j < k; ++j) {
            if (j <= r)
                z[j] = min(r - j + 1, z[j - l]);
            while (j + z[j] < k && s[n-k+z[j]] == s[n-k+j + z[j]])
                ++z[j];
            if (j + z[j] - 1 > r)
                l = j, r = j + z[j] - 1;
            m = max(m, z[j]);
        }
        ans += k - m;
    }

    cout << ans;
    return 0;
}