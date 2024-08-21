// #수학 #정수론 #gcd
// mp에 i이전 모든 gcd과 처음 나오는 위치를 저장
// mp2에 다음 x와의 gcd값을 갱신
//! 결국 gcd를 갱신할수록 값이 1/2이하로 작아지므로 gcd의 값이 log로 감소 -> 개수도 감소
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

    ll t;
    cin >> t;
    while (t--) {
        ll n, x;
        cin >> n;

        ll res = 0;
        map<ll, ll> mp;
        for (ll i = 0; i < n; i++) {
            cin >> x;
            if (mp.find(x) == mp.end()) mp[x] = i;
            else mp[x] = min(mp[x], i);
            map<ll, ll> mp2;
            for (auto [k, v] : mp) {
                ll tmp = gcd(x, k);
                if (mp2.find(tmp) == mp2.end()) mp2[tmp] = v;
                else mp2[tmp] = min(mp2[tmp], v);
                res = max(res, tmp * (i - mp2[tmp] + 1));
            }
            mp = mp2;
        }
        cout << res << '\n';
    }

    return 0;
}