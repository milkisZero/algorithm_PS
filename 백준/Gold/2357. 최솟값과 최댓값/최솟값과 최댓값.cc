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
pll seg[MAX * 4];

void create_seg(ll node, ll start, ll end) {
    if (start == end) {
        seg[node] = {arr[start], arr[start]};
        return;
    }
    
    ll mid = (start + end) / 2;
    create_seg(node * 2, start, mid);
    create_seg(node * 2 + 1, mid + 1, end);
    seg[node] = {max(seg[node * 2].first, seg[node * 2 + 1].first), min(seg[node * 2].second, seg[node * 2 + 1].second)};
}

pll query(ll node, ll start, ll end, ll left, ll right) {
    if (start > right || end < left)
        return {-1, LLINF};
    if (left <= start && end <= right)
        return seg[node];

    ll mid = (start + end) / 2;
    pll a = query(node * 2, start, mid, left, right);
    pll b = query(node * 2 + 1, mid + 1, end, left, right);
    return {max(a.first, b.first), min(a.second, b.second)};
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
        pll res = query(1, 1, n, a, b);
        cout << res.second << ' ' << res.first << '\n';
    }

    return 0;
}