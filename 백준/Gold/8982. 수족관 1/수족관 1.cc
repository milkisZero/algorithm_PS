#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

map<int, int> m;

int main() {
    fastio;

    int n, k;
    cin >> n;

    int sum = 0;
    vector<pi> v(n + 1);
    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
        if (i > 0)
            sum += (v[i].first - v[i - 1].first) * v[i].second;
    }

    cin >> k;
    for (int i = 0; i < k; i++) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;

        int idx;
        for (int j = 0; j < n; j++) {
            if (v[j].first == a && v[j].second == b) {
                idx = j;
                break;
            }
        }
        m.insert({c, d});

        int high = b;
        for (int j = idx - 1; j >= 0; j -= 2) {
            high = min(high, v[j].second);
            m[v[j].first] = max(m[v[j].first], high);
        }

        high = b;
        for (int j = idx + 1; j < n; j += 2) {
            high = min(high, v[j].second);
            m[v[j].first] = max(m[v[j].first], high);
        }
    }

    int res = 0;
    for (int i = 1; i < n; i++) {
        res += (v[i].first - v[i - 1].first) * m[v[i].first];
    }

    cout << sum - res;

    return 0;
}