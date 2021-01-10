#include <iostream>
#include <vector>
#include <string>

using namespace std;


int main() {
    string s;
    cin >> s;
    vector<int> p (s.length());

    for (int i = 1; i < s.length(); i++) {
        int j = p[i-1];
        while (j > 0 && s[i] != s[j]) {
            j = p[j - 1];
        }
        if (s[i] == s[j]) {
            j++;
        }
        p[i] = j;
    }

    for(int i = 0; i < p.size(); i++) {
        cout << p[i] << " ";
    }

    return 0;
}