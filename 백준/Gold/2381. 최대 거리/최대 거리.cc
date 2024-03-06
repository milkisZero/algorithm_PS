#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <climits>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

vector<pi> v;

int cmp1(pi a, pi b) {
    return (a.first - a.second) > (b.first - b.second);
}

int cmp2(pi a, pi b) {
    return (a.first + a.second) > (b.first + b.second);
}

int main() {
    fastio;

    int n;
    cin >> n;

    int a, b;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({a, b});
    }

    sort(v.begin(), v.end(), cmp1);
    int r1 = (v[0].first - v[0].second) - (v[n - 1].first - v[n - 1].second);

    sort(v.begin(), v.end(), cmp2);
    int r2 = (v[0].first + v[0].second) - (v[n - 1].first + v[n - 1].second);

    cout << max(abs(r1), abs(r2));

    return 0;
}