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
#define MAX 100005

ll arr[MAX];
ll seg[MAX * 4];

void create_seg(ll node, ll start, ll end) {
    if (start == end) {
        seg[node] = arr[start];
        return;
    }

    ll mid = (start + end) / 2;
    create_seg(node * 2, start, mid);
    create_seg(node * 2 + 1, mid + 1, end);
    seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
}

ll query(ll node, ll start, ll end, ll left, ll right) {
    if (start > right || end < left)
        return LLINF;
    if (left <= start && end <= right)
        return seg[node];

    ll mid = (start + end) / 2;
    ll a = query(node * 2, start, mid, left, right);
    ll b = query(node * 2 + 1, mid + 1, end, left, right);
    return min(a, b);
}

int main() {
    fastio;

    ll n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }
    create_seg(1, 1, n);

    while (m--) {
        ll a, b;
        cin >> a >> b;
        ll res = query(1, 1, n, a, b);
        cout << res << '\n';
    }

    return 0;
}