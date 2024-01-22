#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#define INF 0x7fffffff
#define LLINF 0x7f7f7f7f7f7f
#define fastio() ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;

ll n, b;
map<string, vector<pll>> info;

ll bs(ll mini, ll maxi) {
    ll l = mini, r = maxi, m, res = -1;
    while (l <= r) {
        m = (l + r) / 2;

        ll sum = 0, mini_qal = LLINF;
        int check = 0;
        for (auto iter = info.begin(); iter != info.end(); iter++) {
            vector<pll> v = iter->second;

            ll mini = -1;
            for (int i = 0; i < v.size(); i++) {
                if (v[i].second >= m && (mini == -1 || v[mini].first > v[i].first))
                    mini = i;
            }

            if (mini == -1) {
                check = 1;
                break;
            }

            sum += v[mini].first;
            mini_qal = min(mini_qal, v[mini].second);
        }

        if (sum > b || check) {
            r = m - 1;
        }
        else {
            l = m + 1;
            res = max(res, mini_qal);
        }
    }
    return res;
}

int main() {
    fastio();

    int T;
    cin >> T;

    while (T--) {
        cin >> n >> b;

        string s, q;
        ll cost, val;
        ll maxi = 0, mini = LLINF;
        for (int i = 0; i < n; i++) {
            cin >> s >> q;
            cin >> cost >> val;

            if (info.find(s) == info.end()) {
                vector<pll> v;
                info.insert({s, v});
            }
            info[s].push_back({cost, val});

            maxi = max(maxi, val);
            mini = min(mini, val);
        }

        cout << bs(mini, maxi) << '\n';

        info.clear();
    }

    return 0;
}