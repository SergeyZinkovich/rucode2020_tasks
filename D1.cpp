#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string A, B;
    std::cin >> A >> B;

    std::vector<std::vector<int>> L(A.length() + 1, std::vector<int>(B.length() + 1, 0));
    for (int i = 0; i <= A.length(); i++) {
        L[i][0] = i;
    }
    for (int i = 0; i <= B.length(); i++) {
        L[0][i] = i;
    }

    for (int j = 1; j <= B.length(); j++) {
        for (int i = 1; i <= A.length(); i++) {
            L[i][j] = std::min(std::min(
                    L[i - 1][j] + 1, L[i][j - 1] + 1),
                               L[i - 1][j - 1] + (A[i - 1] == B[j - 1] ? 0 : 1));
        }
    }

    std::cout << L[A.length()][B.length()] << std::endl;
    return 0;
}