#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL);
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;
#define MAX 1000006

ll arr[MAX * 4];
ll segtree[MAX * 4];

void update_seg(ll node, ll start, ll end, ll target, ll val) {
    if (start > target || end < target)
        return;
    if (start == end) {
        segtree[node] += val;
        return;
    }

    segtree[node] += val;
    ll mid = (start + end) / 2;
    update_seg(node * 2, start, mid, target, val);
    update_seg(node * 2 + 1, mid + 1, end, target, val);
}

ll query(ll node, ll start, ll end, ll left, ll right) {
    if (start > right || end < left)
        return 0;
    if (left <= start && end <= right)
        return segtree[node];

    ll mid = (start + end) / 2;
    return query(node * 2, start, mid, left, right) + query(node * 2 + 1, mid + 1, end, left, right);
}

int main() {
    fastio;

    ll n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        ll a, b, c;
        cin >> a >> b >> c;

        if (!a) {
            if (b > c)
                swap(b, c);
            cout << query(1, 1, n, b, c) << '\n';
        }
        else {
            update_seg(1, 1, n, b, -arr[b] + c);
            arr[b] = c;
        }
    }

    return 0;
}