#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

pair<long long, long long> points[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> points[i].first >> points[i].second;
    }

    long double res = 0;
    for (int i = 1; i < n - 1; i++) {
        long double tmp = points[0].first * points[i].second + points[i].first * points[i + 1].second + points[i + 1].first * points[0].second;
        tmp = (tmp - (points[0].second * points[i].first + points[i].second * points[i + 1].first + points[i + 1].second * points[0].first));

        res += tmp;
    }

    res /= 2;
    res = res < 0 ? -res : res;

    cout << fixed;
    cout.precision(1);

    cout << res;

    return 0;
}