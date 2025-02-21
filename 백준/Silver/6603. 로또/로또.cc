#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
#define sp ' '
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

int main() {
    fastio;

    while (1) {
        ll t;
        cin >> t;
        if (!t) break;

        vector<ll> v(t);
        for (int i = 0; i < t; i++) cin >> v[i];

        vector<ll> v2;
        for (int i = 0; i < t - 6; i++) v2.push_back(0);
        for (int i = t - 6; i < t; i++) v2.push_back(1);

        vector<vector<ll>> res;
        do {
            vector<ll> v3;
            for (int i = 0; i < t; i++) {
                if (v2[i]) v3.push_back(v[i]);
            }

            res.push_back(v3);
        } while (next_permutation(v2.begin(), v2.end()));

        sort(res.begin(), res.end());
        for (auto e : res) {
            for (auto e1 : e) cout << e1 << sp;
            cout << endl;
        }
        cout << endl;
    }

    return 0;
}