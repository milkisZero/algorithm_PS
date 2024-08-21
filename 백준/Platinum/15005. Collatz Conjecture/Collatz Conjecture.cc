// #수학 #정수론 #gcd
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

    ll n, x;
    cin >> n;

    set<ll> res, st;
    for (int i = 0; i < n; i++) {
        cin >> x;
        st.insert(x);
        res.insert(x);
        set<ll> st2;
        for (auto v : st) {
            ll tmp = gcd(x, v);
            st2.insert(tmp);
            res.insert(tmp);
        }
        st = st2;
    }
    cout << res.size() << '\n';

    return 0;
}