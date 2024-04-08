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

    ll a, b, tmp;
    cin >> a >> b;
    set<ll> av, bv;
    for (int i = 0; i < a + b; i++) {
        cin >> tmp;
        if (i < a) av.insert(tmp);
        else bv.insert(tmp);
    }

    ll sum = 0, k = 0;
    for (auto e : av) {
        if (*bv.lower_bound(e) == e)
            k++;
    }
    sum = av.size() - k;
    k = 0;
    for (auto e : bv) {
        if (*av.lower_bound(e) == e)
            k++;
    }
    cout << sum + bv.size() - k;

    return 0;
}