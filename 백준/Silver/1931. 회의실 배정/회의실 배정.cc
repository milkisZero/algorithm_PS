#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

int cmp(pi a, pi b) {
    if (a.second == b.second)
        return a.first < b.first;
    return a.second < b.second;
}

int main() {
    fastio;

    int n;
    cin >> n;

    vector<pi> v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), cmp);

    pi p = v[0];
    int cnt = 1;
    for (int i = 1; i < n; i++) {
        if (p.second > v[i].second)
            p = v[i];
        else if (p.second <= v[i].first) {
            p = v[i];
            cnt++;
        }
    }

    cout << cnt;

    return 0;
}