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
#define MAXSIZE 1000001

ll segtree[MAXSIZE * 4], lazy[MAXSIZE * 4];

void update_lazy(int node, int start, int end) {
    // 현재 노드의 lazy값을 반영함
    if (lazy[node] != 0) {
        segtree[node] += ((ll)end - start + 1) * lazy[node]; // 구간의 크기만큼 반영
        if (start != end) {
            // 구간 노드라면, 양쪽 자식에 lazy값을 물려줌
            lazy[node * 2] += lazy[node];
            lazy[node * 2 + 1] += lazy[node];
        }
        lazy[node] = 0; // 초기화
    }
}

void update_range(int node, int start, int end, int l, int r, ll val) {
    // 구간 갱신 함수
    update_lazy(node, start, end); // 방문하는 노드에 대해 lazy 값이 있다면 반영

    if (l > end || r < start)
        return; // 포함되지 않는 범위

    // 완전히 포함되는 범위
    if (l <= start && end <= r) {
        segtree[node] += ((ll)end - start + 1) * val; // 구간의 크기만큼 '현재 노드에만' 반영
        if (start != end) {
            // 구간 노드라면, 양쪽 자식에 lazy값을 추가
            lazy[node * 2] += val;
            lazy[node * 2 + 1] += val;
        }
        return;
    }

    // 걸치는 범위
    int mid = (start + end) / 2;
    update_range(node * 2, start, mid, l, r, val);
    update_range(node * 2 + 1, mid + 1, end, l, r, val);
    segtree[node] = segtree[node * 2] + segtree[node * 2 + 1];
}

ll query(int node, int start, int end, int l, int r) {
    // 구간 쿼리 함수
    update_lazy(node, start, end); // 방문하는 노드에 대해 lazy 값이 있다면 반영

    if (l > end || r < start)
        return 0; // 포함되지 않는 범위

    // 완전히 포함되는 범위
    if (l <= start && end <= r)
        return segtree[node];

    // 걸치는 범위
    int mid = (start + end) / 2;
    return query(node * 2, start, mid, l, r) + query(node * 2 + 1, mid + 1, end, l, r);
}

int main() {
    fastio;

    ll n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        ll a, b;
        cin >> a >> b;

        ll k = query(1, 1, MAXSIZE, a, a);
        ll p = query(1, 1, MAXSIZE, b, b);
        if (i > 0) {
            update_range(1, 1, MAXSIZE, a, a, -k);
            update_range(1, 1, MAXSIZE, b, b, -p);
        }

        cout << k + p << '\n';

        update_range(1, 1, MAXSIZE, a + 1, b - 1, 1);
    }

    return 0;
}