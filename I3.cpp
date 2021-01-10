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

Point operator -(const Point& a, const Point& b) {
    return Point(a.x - b.x, a.y - b.y);
}

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
    int pos = 0, neg = 0;
    for (int i = 0; i < n; i++) {
        long long curCP = cP(p[(i + 1) % n] - p[i], p[i] - p[(i - 1 + n) % n]);
        if (curCP > 0) {
            pos++;
        } else if (curCP < 0) {
            neg++;
        }
    }
    if (pos * neg == 0) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}