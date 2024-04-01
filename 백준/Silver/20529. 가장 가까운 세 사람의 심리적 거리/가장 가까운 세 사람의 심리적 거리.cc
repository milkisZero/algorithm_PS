#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

int dist(string a, string b, string c) {
    int cnt = 0;
    for (int i = 0; i < 4; i++) {
        if (a[i] != b[i])
            cnt++;
        if (b[i] != c[i])
            cnt++;
        if (a[i] != c[i])
            cnt++;
    }
    return cnt;
}

int main() {
    fastio;

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        vector<string> v;
        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            v.push_back(s);
        }

        if (v.size() > 32) {
            cout << 0 << '\n';
            continue;
        }

        int res = INF;
        for (int i = 0; i < v.size(); i++) {
            for (int j = i + 1; j < v.size(); j++) {
                for (int k = j + 1; k < v.size(); k++) {
                    res = min(res, dist(v[i], v[j], v[k]));
                }
            }
        }

        cout << res << '\n';
    }
    return 0;
}