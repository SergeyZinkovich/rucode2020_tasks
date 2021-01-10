#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>
#include <vector>

using namespace std;

struct pt {
    double x, y;
};

struct line {
    double a, b, c;
};

const double EPS = 1e-9;

double det (double a, double b, double c, double d) {
    return a * d - b * c;
}

bool intersect (line m, line n, pt & res) {
    double zn = det (m.a, m.b, n.a, n.b);
    if (abs (zn) < EPS)
        return false;
    res.x = - det (m.c, m.b, n.c, n.b) / zn;
    res.y = - det (m.a, m.c, n.a, n.c) / zn;
    return true;
}

bool equivalent (line m, line n) {
    return abs (det (m.a, m.b, n.a, n.b)) < EPS
           && abs (det (m.a, m.c, n.a, n.c)) < EPS
           && abs (det (m.b, m.c, n.b, n.c)) < EPS;
}

int main() {
    double px1, py1, qx1, qy1, px2, py2, qx2, qy2;
    cin >> px1 >> py1 >> qx1 >> qy1 >> px2 >> py2 >> qx2 >> qy2;
    line l1, l2;
    l1.a = py1 - qy1;
    l1.b = qx1 - px1;
    l1.c = -l1.a * px1 - l1.b * py1;
    l2.a = py2 - qy2;
    l2.b = qx2 - px2;
    l2.c = -l2.a * px2 - l2.b * py2;
    if (equivalent(l1, l2)) {
        cout << 2;
        return 0;
    }
    pt a;
    if (intersect(l1, l2, a))
        cout << setprecision(13) << fixed << "1\n" << a.x << " " << a.y;
    else
        cout << 0;



    return 0;
}