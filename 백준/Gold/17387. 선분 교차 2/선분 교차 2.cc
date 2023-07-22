// #선분교차 #ccw
#include <iostream>
#include <vector>
using namespace std;

typedef pair<long long, long long> point;

int ccw(point a, point b, point c) {
    point ab, ac;
    ab.first = b.first - a.first, ab.second = b.second - a.second;
    ac.first = c.first - a.first, ac.second = c.second - a.second;

    long long res = ab.first * ac.second - ab.second * ac.first;

    if (res > 0)
        return 1;
    else if (res == 0)
        return 0;
    else
        return -1;
}

int check(point a, point b, point c) {
    point c1, c2;

    if ((a.first - c.first == 0 && a.second - c.second == 0) || (b.first - c.first == 0 && b.second - c.second == 0))
        return 1;

    c1.first = a.first - c.first, c1.second = a.second - c.second;
    c2.first = b.first - c.first, c2.second = b.second - c.second;

    if ((c1.first * c2.first < 0) || (c1.second * c2.second < 0))
        return 1;
    else
        return -1;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    point a, b, c, d;
    cin >> a.first >> a.second >> b.first >> b.second;
    cin >> c.first >> c.second >> d.first >> d.second;

    if ((ccw(a, b, c) == 0 && check(a, b, c) == 1) || (ccw(a, b, d) == 0 && check(a, b, d) == 1)) {
        cout << 1;
        return 0;
    }
    else if ((ccw(c, d, a) == 0 && check(c, d, a) == 1) || (ccw(c, d, b) == 0 && check(c, d, b) == 1)) {
        cout << 1;
        return 0;
    }
    else if (ccw(a, b, c) == 0 && ccw(a, b, d) == 0) {
        cout << 0;
        return 0;
    }

    if (ccw(a, b, c) == ccw(a, b, d) * -1 && ccw(c, d, a) == ccw(c, d, b) * -1)
        cout << 1;
    else
        cout << 0;

    return 0;
}