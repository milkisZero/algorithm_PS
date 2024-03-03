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
ll n, p;
pll price[51];
vector<ll> v[4];
double res = INF;

void func(ll a, ll b, ll c) {
    ll cnt = 0;
    double k = p;

    for (int i = 0; i < a; i++) {
        k *= 0.99;
        cnt += v[1][i];
    }
    for (int i = 0; i < b; i++) {
        k *= 0.98;
        cnt += v[2][i];
    }
    for (int i = 0; i < c; i++) {
        k *= 0.97;
        cnt += v[3][i];
    }

    res = min(res, k + cnt);
}

int main() {
    fastio;

    cin >> n >> p;

    for (int i = 0; i < n; i++) {
        cin >> price[i].first >> price[i].second;
        v[price[i].second].push_back(price[i].first);
    }

    for (int i = 1; i <= 3; i++) {
        sort(v[i].begin(), v[i].end());
    }

    for (int i = 0; i <= n && i <= v[1].size(); i++) {
        for (int j = 0; i + j <= n && j <= v[2].size(); j++) {
            for (int k = 0; i + j + k <= n && k <= v[3].size(); k++) {
                func(i, j, k);
            }
        }
    }

    cout << fixed;
    cout.precision(6);
    cout << res;

    return 0;
}
