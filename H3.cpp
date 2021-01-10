#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>


using namespace std;

int main() {
    double x1, y1, x2, y2, x3, y3, x0, y0;
    cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x0 >> y0;

    double a = (x1 - x0) * (y2 - y1) - (x2 - x1) * (y1 - y0);
    double b = (x2 - x0) * (y3 - y2) - (x3 - x2) * (y2 - y0);
    double c = (x3 - x0) * (y1 - y3) - (x1 - x3) * (y3 - y0);

    if ((a >= 0 && b >= 0 && c >= 0) || (a <= 0 && b <= 0 && c <= 0)) {
        cout << "In";
    } else {
        cout << "Out";
    }

    return 0;
}