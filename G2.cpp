#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


int main() {
    string s;
    cin >> s;
    vector<int> p (s.length());
    vector<int> d (s.length());

    for (int i = 1; i < s.length(); i++) {
        int j = p[i-1];
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        d[i] = d[j];
        if (s[i] == s[j]) {
            d[i]++;
            j++;
        }
        p[i] = j;
    }

    auto m = max_element(d.begin(), d.end()) - d.begin();

    for(int i = 0; i <= m; i++) {
        cout << s[i];
    }

    return 0;
}