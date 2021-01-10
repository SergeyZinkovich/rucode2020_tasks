#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <iomanip>
#include <cmath>
#include <algorithm>
#include <deque>

using namespace std;

int a, b;

unsigned int cur = 0;
unsigned int nextRand24() {
    cur = cur * a + b;
    return cur >> 8;
}

unsigned int nextRand32() {
    unsigned int a = nextRand24(), b = nextRand24();
    return (a << 8) ^ b;
}

bool comparator(pair<unsigned int, unsigned int> left, pair<unsigned int, unsigned int> right)
{
    return left.first < right.first;
}

bool comparator2(pair<unsigned int, unsigned int> left, pair<unsigned int, unsigned int> right)
{
    return left.first == right.first;
}

int main() {
    int n, q;
    cin >> n >> q >> a >> b;
    vector<unsigned int> coords(n);
    vector<pair<unsigned int, unsigned int>> bounds;
    vector<pair<unsigned int, unsigned int>> arr;

    arr.reserve(n+2*q);
    bounds.reserve(q);

    for (int i = 0; i < n; i++) {
        unsigned int value, x;
        value = nextRand32();
        x = nextRand32();
        arr.emplace_back(x, value);
    }

    for (int i = 0; i < n; i++) {
        unsigned int l, r;
        l = nextRand32();
        r = nextRand32();
        if (l > r) swap(l, r);
        bounds.emplace_back(make_pair(l, r));
//        arr.emplace_back(l, 0);
//        arr.emplace_back(r, 0);
    }

    sort(arr.begin(), arr.end(), comparator);

//    for (int i = n+2*q-2; i >= 0; i--) {
//        if (arr[i].first == arr[i+1].first) {
//            arr[i].second = max(arr[i].second, arr[i+1].second);
//            arr.erase(arr.begin()+i+1);
//        }
//    }

//    arr.erase(unique(arr.begin(), arr.end(), comparator2), arr.end());

    vector<unsigned long long> p(size(arr));
    p[0] = arr[0].second;
    for (int i = 1; i < size(arr); i++) {
        p[i] = p[i-1] + arr[i].second;
    }

    unsigned int ans = 0;
    for (int i = 0; i < q; i++) {
        auto l = lower_bound(arr.begin(), arr.end(), make_pair(bounds[i].first, 0), comparator) - arr.begin();
        auto r = upper_bound(arr.begin(), arr.end(), make_pair(bounds[i].second, 0), comparator) - arr.begin() - 1;
        ans += p[r] - (l > 0 ? p[l-1]: 0);
    }

    cout << ans;

    return 0;
}