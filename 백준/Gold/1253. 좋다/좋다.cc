#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

int main() {
    fastio;

    ll n;
    cin >> n;
    vector<ll> v(n);
    for (auto &e : v) cin >> e;

    sort(v.begin(), v.end());

    set<ll> st;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll k = lower_bound(v.begin(), v.end(), v[i] - v[j]) - v.begin();
            while (k == i || k == j) k++;
            if (v[j] + v[k] == v[i] && j != k && j != i && i != k) {
                st.insert(i);
                break;
            }
        }
    }

    cout << st.size();
    return 0;
}