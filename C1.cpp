#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    string s, mask;
    getline(cin, s);
    getline(cin, mask);

    string tmp;
    for (int i = 0; i < (int)s.size(); i++) {
        if (!(i > 0 && tmp.back() == '*' && s[i] == '*')) {
            tmp.push_back(s[i]);
        }
    }
    s = tmp;

    vector<vector<bool>> d(s.size() + 1, vector<bool>(mask.size() + 1, false));
    d[0][0] = true;

    if (s[0] == '*') {
        for (int i = 0; i <= mask.size(); i++) {
            d[1][i] = true;
        }
    }

    for (int i = 1 + (s[0] == '*' ? 1 : 0); i <= (int)s.size(); i++)  {
        for (int j = 1; j <= (int)mask.size(); j++) {
            if (s[i - 1] == '?') {
                d[i][j] = d[i - 1][j - 1];
            } else if (s[i - 1] == '*') {
                d[i][j] = d[i - 1][j] || d[i][j - 1];
            } else {
                if (s[i - 1] == mask[j - 1]) {
                    d[i][j] = d[i - 1][j - 1];
                } else {
                    d[i][j] = false;
                }
            }
        }
    }

    cout << (d[s.size()][mask.size()] ? "YES" : "NO");

    return 0;
}