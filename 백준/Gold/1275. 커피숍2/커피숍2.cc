// #세그
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

void create_seg(ll node, ll start, ll end) {
    if (start == end) {
        segtree[node] = arr[start];
        return;
    }
    ll mid = (start + end) / 2;
    create_seg(node * 2, start, mid);
    create_seg(node * 2 + 1, mid + 1, end);
    segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

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

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    create_seg(1, 1, n);

    for (int i = 0; i < m; i++) {
        ll a, b, c, d;
        cin >> a >> b >> c >> d;

        if (a > b)
            swap(a, b);

        cout << query(1, 1, n, a, b) << '\n';
        update_seg(1, 1, n, c, -arr[c] + d);
        arr[c] = d;
    }

    return 0;
}