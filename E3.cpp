#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

int main() {
    double x1, y1, x2, y2, x3, y3;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;

    double mx = x1 + 0.5 * (x2 - x1);
    double my = y1 + 0.5 * (y2 - y1);
    double ansx = x3 + ((double) 2 / 3) * (mx - x3);
    double ansy = y3 + ((double) 2 / 3) * (my - y3);

    cout << setprecision(13) << fixed << ansx << " " << ansy;

    return 0;
}