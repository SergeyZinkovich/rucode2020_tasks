#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    string s = s2 + '#' + s1;

    int n = (int) s.length();
    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }

    int cans = 0;
    vector<int> ans;
    for (int i = s2.length(); i < n; i++) {
        if (pi[i] == s2.length()) {
            cans++;
            ans.push_back(i - 2 * s2.length() + 1);
        }
    }

    cout << cans << endl;
    for (int i : ans) {
        cout << i << ' ';
    }

    return 0;
}