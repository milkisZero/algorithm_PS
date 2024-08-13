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

    ll n, k;
    cin >> n >> k;

    deque<ll> dq;
    ll maxi = 0, sum = 0;
    for (int i = 0; i < n; i++) {
        ll a;
        cin >> a;
        dq.push_back(a);
        sum += a;
        if (dq.size() > k) {
            sum -= dq.front();
            dq.pop_front();
        }

        if (dq.size() == k) maxi = max(maxi, sum);
    }

    cout << maxi;

    return 0;
}