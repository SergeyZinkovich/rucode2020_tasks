
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

using namespace std;

struct Point {
    double x, y;
    Point(){}
    Point(double x_, double y_):x(x_), y(y_){}
};

Point operator -(const Point& a, const Point& b) {
    return Point(a.x - b.x, a.y - b.y);
}

double len(const Point& a) {
    return hypot(a.x, a.y);
}

istream& operator >>(istream& in, Point& p) {
    in >> p.x >> p.y;
    return in;
}

int main() {
    Point a, b;
    cin >> a >> b;
    Point c = b - a;
    cout << setprecision(13) << fixed << len(c);
    return 0;
}