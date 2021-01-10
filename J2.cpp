#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> p(n), z(n);

    for (int i = 0; i < n; i++) {
        cin >> z[i];
    }
    z[0] = 0;
    int m = 0;

    for (int j = 0; j < n; j++) {
        p[j] = 0;
        int tmp = m;
        for (int i = m; i <= j; i++){
            if (i + z[i] - 1 >= j) {
                tmp = i - 1;
                p[j] = j - i + 1;
                break;
            }
        }
        m = tmp;
        cout << p[j] << " ";
    }
    return 0;
}