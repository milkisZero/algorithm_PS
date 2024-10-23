#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
#define endl '\n'
using namespace std;
using ll = long long;
using pii = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

set<ll> vidx[500005];
ll inQ[500005];

int main() {
    fastio;

    ll n, k;
    cin >> n >> k;

    vector<ll> v(k);
    for (int i = 0; i < k; i++) {
        cin >> v[i];
        vidx[v[i]].insert(i);
    }

    if (n >= k) {
        cout << 0 << endl;
        return 0;
    }

    priority_queue<pll> pq;

    ll res = 0;
    for (int i = 0; i < k; i++) {
        if (inQ[v[i]]) {
            ll tmp = *vidx[v[i]].begin();
            if (vidx[v[i]].empty()) tmp = LLINF;
            else vidx[v[i]].erase(tmp);

            priority_queue<pll> pq2;
            while (!pq.empty()) {
                if (pq.top().second == v[i])
                    pq2.push({tmp, v[i]});
                else pq2.push(pq.top());
                pq.pop();
            }
            pq = pq2;
            continue;
        }

        if (pq.size() < n) {
            ll tmp = *vidx[v[i]].begin();
            if (i == tmp) {
                vidx[v[i]].erase(i);
            }
            tmp = *vidx[v[i]].begin();

            if (vidx[v[i]].empty()) tmp = LLINF;
            else vidx[v[i]].erase(tmp);
            inQ[v[i]] = 1;
            pq.push({tmp, v[i]});
        }
        else {
            res++;
            inQ[pq.top().second] = 0;
            pq.pop();

            ll tmp = *vidx[v[i]].begin();
            if (i == tmp) {
                vidx[v[i]].erase(i);
            }
            tmp = *vidx[v[i]].begin();
            if (vidx[v[i]].empty()) tmp = LLINF;
            else vidx[v[i]].erase(tmp);

            inQ[v[i]] = 1;
            pq.push({tmp, v[i]});
        }
    }

    cout << res;

    return 0;
}