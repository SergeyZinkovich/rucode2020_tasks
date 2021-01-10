#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s;
    cin >> s;

    vector<int> z (s.length());
    int  l = 0, r = 0;
    for (int i = 1; i < s.length(); i++) {
        if (i <= r) {
            z[i] = min(r - i + 1, z[i - l]);
        }
        while (i + z[i] < s.length() && s[z[i]] == s[i + z[i]]) {
            z[i]++;
        }
        if (i + z[i] - 1 > r) {
            l = i;
            r = i + z[i] - 1;
        }
    }
    z[0] = s.length();


    for(int i = 0; i < z.size(); i++) {
        cout << z[i] << " ";
    }

    return 0;
}