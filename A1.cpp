#include <iostream>

int main() {
    int n;

    std::cin >> n;

    int a[1000];
    for (int i = 0; i < n; i++) {
        std::cin >> a[i];
    }

    int d[1000];

    for (int i=0; i < n; i++) {
        d[i] = 1;
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i]) {
                d[i] = std::max(d[i], 1 + d[j]);
            }
        }
    }

    int m = d[0];
    for (int i=0; i<n; ++i) {
        m = std::max(m, d[i]);
    }
    std::cout << m << std::endl;
    return 0;
}