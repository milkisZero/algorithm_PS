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

    if (ccw(a, b, c) == ccw(a, b, d) * -1 && ccw(c, d, a) == ccw(c, d, b) * -1)
        cout << 1;
    else
        cout << 0;

    return 0;
}