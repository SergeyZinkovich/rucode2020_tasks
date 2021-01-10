#include <iostream>
#include <vector>
#include <string>
#include <math.h>
#include <iomanip>

using namespace std;

int main() {
    float a1, a2, b1, b2;
    cin >> a1 >> a2 >> b1 >> b2;

    float ans = acos((a1 * b1 + a2 * b2) / (sqrt(a1*a1 + a2*a2) * sqrt(b1*b1 + b2*b2)));

    cout << setprecision(13) << fixed << ans;

    return 0;
}