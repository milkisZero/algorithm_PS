#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
#define MAXSIZE 1000001

ll seg[MAXSIZE * 4], lz[MAXSIZE * 4];
ll arr[MAXSIZE];

void init(ll node, ll start, ll end) {
    if (start == end) {
        seg[node] = arr[start];
        return;
    }
    ll mid = (start + end) / 2;
    init(node * 2, start, mid);
    init(node * 2 + 1, mid + 1, end);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

void update_lazy(ll node, ll start, ll end) {
    if (lz[node] != 0) {
        seg[node] += (end - start + 1) * lz[node];
        if (start != end) {
            lz[node * 2] += lz[node];
            lz[node * 2 + 1] += lz[node];
        }
        lz[node] = 0;
    }
}

void update_range(ll node, ll start, ll end, ll l, ll r, ll val) {
    update_lazy(node, start, end);
    if (l > end || r < start) return;
    else if (l <= start && end <= r) {
        seg[node] += (end - start + 1) * val;
        if (start != end) {
            lz[node * 2] += val;
            lz[node * 2 + 1] += val;
        }
        return;
    }

    ll mid = (start + end) / 2;
    update_range(node * 2, start, mid, l, r, val);
    update_range(node * 2 + 1, mid + 1, end, l, r, val);
    seg[node] = seg[node * 2] + seg[node * 2 + 1];
}

ll query(ll node, ll start, ll end, ll l, ll r) {
    update_lazy(node, start, end);
    if (l > end || r < start) return 0;
    else if (l <= start && end <= r) return seg[node];

    ll mid = (start + end) / 2;
    return query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l, r);
}

int main() {
    fastio;

    ll n, a, b;
    cin >> n >> a >> b;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    init(1, 1, n);

    ll t, l, r, p;
    for (int i = 0; i < a + b; i++) {
        cin >> t;
        if (t == 1) {
            cin >> l >> r;
            cout << query(1, 1, n, l, r) << '\n';
        }
        else {
            cin >> l >> r >> p;
            update_range(1, 1, n, l, r, p);
        }
    }

    return 0;
}