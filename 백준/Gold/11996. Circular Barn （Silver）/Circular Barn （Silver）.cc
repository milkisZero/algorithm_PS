#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

ll ori[1004], arr[1004], score[1004];

int main() {
    fastio;

    ll n;
    cin >> n;

    for (int i = 1; i <= n; i++) cin >> ori[i];

    ll res = LLINF;
    for (int j = 1; j <= n; j++) {
        for (int i = 1; i <= n; i++) arr[i] = ori[i];
        fill(score, score + n + 1, 0);

        while (1) {
            ll k = 0;
            for (int i = j; i <= n; i++) {
                ll next = i + 1;
                if (i + 1 > n) next = 1;
                if (arr[i] && arr[next] == 0) {
                    arr[i]--, arr[next]++;
                    score[next] = score[i] + 1;
                    score[i] = 0;
                    k = 1;
                }
            }
            for (int i = 1; i < j; i++) {
                ll next = i + 1;
                if (arr[i] && arr[next] == 0) {
                    arr[i]--, arr[next]++;
                    score[next] = score[i] + 1;
                    score[i] = 0;
                    k = 1;
                }
            }
            if (!k) break;
        }

        ll sum = 0;
        for (int i = 1; i <= n; i++) sum += score[i] * score[i];
        res = min(res, sum);
    }

    cout << res;

    return 0;
}