#include <iostream>
#include <string>
#include <vector>


using namespace std;

int main() {
    string s;

    cin >> s;

    int n = (int)s.length();
    vector<int> o(n+1), c(n+1);

    for (int i = 1; i <= n; i++) {
        o[i] = o[i-1];
        c[i] = c[i-1];
        if (s[i-1] == '(') {
            o[i] += 1;
        }
        if (s[i-1] == ')') {
            c[i] += 1;
        }
    }

    int k;
    cin >>k;

    for (int i = 0; i < k; i++) {
        int l, r;
        cin >> l >> r;
        cout << (o[r] - o[l-1] == c[r] - c[l-1] ? 1 : 0);
    }
    return 0;
}