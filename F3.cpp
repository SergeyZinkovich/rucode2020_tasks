#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double len1 = sqrt(pow(x3 - x1, 2) + pow(y3 - y1, 2));
    double len2 = sqrt(pow(x3 - x2, 2) + pow(y3 - y2, 2));
    double len3 = sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));

    double ansx = (len2 * x1 + len1 * x2 + len3 * x3) / (len1 + len2 + len3);
    double ansy = (len2 * y1 + len1 * y2 + len3 * y3) / (len1 + len2 + len3);

    cout << setprecision(13) << fixed << ansx << " " << ansy;

    return 0;
}