#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    vector<vector<int>> d(2, vector<int>(n, 0));

    for (int i = 0; i < n; i++) {
        cin >> A[i];
    }

    int dropped = 0, state = 0;


    for (int i = 1; i < n; i++) {
        if ((A[i] > A[i - 1]) && ((state == 1) || (state == 0))) {
            state = -1;
        } else if ((A[i] < A[i - 1]) && ((state == -1) || (state == 0))) {
            state = 1;
        } else {
            dropped += 1;
        }

    }

    std::cout << dropped;
    return 0;
}