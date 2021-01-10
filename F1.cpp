#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, k, t;
    cin >> n >> k >> t;
    vector<int> T(n), P(n), S(n);
    vector<vector<int>> d(n, vector<int>(k + 1, 0));

    for (int i = 0; i < n; i++) {
        cin >> T[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> P[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> S[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (T[i] > T[j]) {
                swap(T[i], T[j]);
                swap(P[i], P[j]);
                swap(S[i], S[j]);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (i != 0) {
                int mm = -1;
                for (int m = 0; m <= k; m++) {
                    if ((abs(j - m) <= T[i] - T[i - 1]) && ((mm == -1) || (d[i - 1][mm] < d[i - 1][m]))) {
                        mm = m;
                    }
                }
                if (mm != -1) {
                    d[i][j] = d[i - 1][mm];
                }
                if ((j <= T[i]) && (j == S[i])) {
                    d[i][j] += P[i];
                }
            } else {
                if (j == S[i] && j <= T[i]) {
                    d[i][j] = P[i];
                }
            }
        }
    }

    int mmm = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j <= k; j++) {
            if (mmm < d[i][j]) {
                mmm = d[i][j];
            }
        }
    }

    cout << mmm;
    return 0;
}