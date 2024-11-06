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

pll point[100001];

// 벡터AB와 벡터AC의 내적
ll ccw(pll a, pll b, pll c) {
    auto [af, as] = a;
    auto [bf, bs] = b;
    auto [cf, cs] = c;
    return (bf - af) * (cs - as) - (bs - as) * (cf - af);
}

ll dist(pll a, pll b) {
    auto [af, as] = a;
    auto [bf, bs] = b;
    return (af - bf) * (af - bf) + (as - bs) * (as - bs);
}

// 반시계 방향으로 정렬
bool ccw_cmp(pll a, pll b) {
    ll c = ccw(point[0], a, b);
    if (c == 0) return dist(point[0], a) < dist(point[0], b);
    return c > 0;
}

int main() {
    fastio;

    ll n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll x, y;
        cin >> x >> y;
        point[i] = {x, y};
    }
    sort(point, point + n, [](pll a, pll b) { 
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second; });
    sort(point + 1, point + n, ccw_cmp);

    stack<pll> st;
    for (int i = 0; i < n; i++) {
        while (st.size() >= 2) {
            pll b = st.top();
            st.pop();
            pll a = st.top();

            // i-b와 b-a가 반시계일 때까지 pop -> 가장 큰 각도의 도형
            if (ccw(point[i], a, b) > 0) {
                st.push(b);
                break;
            }
        }
        st.push(point[i]);
    }
    cout << st.size();

    return 0;
}