#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

using namespace std;

const double EPS = 0.000000001;

struct Point {
    Point() {};

    double x;
    double y;
};

struct Vector {
    Vector() {}

    double x, y;
};

double operator*(Vector left, Vector right) {
    return left.x * right.x + left.y * right.y;
}

Vector operator*(Vector left, double scalar) {
    Vector result;
    result.x = left.x * scalar;
    result.y = left.y * scalar;
    return result;
}

Vector operator-(Point left, Point right) {
    Vector result;
    result.x = left.x - right.x;
    result.y = left.y - right.y;
    return result;
}

struct Line {
    Line(double a, double b, double c) {
        if (fabs(b) < EPS) {
            begin.x = -c / a;
            end.x = -c / a;

            begin.y = 0;
            begin.y = 10;
        } else {
            begin.x = 0;
            end.x = 10;
            begin.y = - (c + (a * begin.x)) / b;
            end.y = - (c + (a * end.x)) / b;
        }
    }

    Point begin, end;
};


Point operator+(Point p, Vector v) {
    p.x += v.x;
    p.y += v.y;
    return p;
}

pair<int, pair<double, double>> solve_quad(double a, double b, double c) {
    double x1, x2;

    long  double D = b * b - 4 * a * c;
    if (fabs(a) < EPS && fabs(b) < EPS && fabs(c) < EPS){
        return {4, {}};
    }

    if (fabs(a) < EPS && fabs(b) < EPS) {
        return {0, {}};
    }

    if(fabs(a) < EPS){
        x1 = c * (-1.0) / b;
        return { 1, {x1, x1 } };
    }

    if (D < 0.0){
        return { 0, {}};
    } else if (fabs(D) < EPS){
        x1 = (b * (-1)) / (2 * a);
        return { 1, {x1, x1}};
    } else {
        x1 = (b * (-1.0) - sqrt(D)) / (2 * a);
        x2 = (b * (-1.0) + sqrt(D)) / (2 * a);

        if(x2 < x1) {
            swap(x1, x2);
        }
        return {2, {x1, x2}};
    }
}

pair<int, pair<Point, Point>> cross(Line line1, Point center, double r) {
    pair<int, pair<double, double>> sol = solve_quad((line1.end - line1.begin) * (line1.end - line1.begin), 2 * ((line1.end - line1.begin) * (line1.begin - center)), (line1.begin - center) * (line1.begin - center) - r * r);

    if (sol.first == 0) {
        return {0, {}};
    } else if (sol.first == 1) {
        Point point = line1.begin +  (line1.end - line1.begin) * sol.second.first;
        return { 1, {point, point}};
    } else {
        Point point1 = line1.begin + (line1.end - line1.begin) * sol.second.first;
        Point point2 = line1.begin + (line1.end - line1.begin) * sol.second.second;

        return { 2, {point1, point2}};
    }
}

int main() {
    Point center;
    long double r, a, b, c;
    cin >> center.x >> center.y >> r >> a >> b >> c;

    pair<int, pair<Point, Point>> res = cross(Line(a, b, c), center, r);

    cout << res.first << endl;
    if (res.first > 0) {
        cout << fixed << setprecision(5) << res.second.first.x << " " << res.second.first.y << endl;
    }
    if (res.first > 1) {
        cout << fixed << setprecision(5) << res.second.second.x << " " << res.second.second.y << endl;
    }
}