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

    ll n;
    cin >> n;

    priority_queue<ll, vector<ll>, greater<>> pq;
    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        pq.push(tmp);
    }

    ll cnt = 0;
    while (pq.size() >= 2) {
        ll a, b;
        a = pq.top();
        pq.pop();
        b = pq.top();
        pq.pop();

        cnt += a + b;
        pq.push(a + b);
    }

    cout << cnt;

    return 0;
}