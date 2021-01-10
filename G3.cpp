#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

struct Point {
    double x, y;
    Point(){}
    Point(double x_, double y_):x(x_), y(y_){}
};

long double cP(const Point& a, const Point& b) {
    return a.x * b.y - a.y * b.x;
}

istream& operator >>(istream& in, Point& p) {
    in >> p.x >> p.y;
    return in;
}

int main() {
    int n;
    cin >> n;
    vector<Point> p(n);
    for (int i = 0; i < n; i++) {
        cin >> p[i];
    }
    long double squere = 0;
    for (int i = 0; i < n; i++) {
        squere += cP(p[i], p[(i + 1) % n]);
    }
    cout << fixed << setprecision(20) << abs(squere / 2) << endl;
}