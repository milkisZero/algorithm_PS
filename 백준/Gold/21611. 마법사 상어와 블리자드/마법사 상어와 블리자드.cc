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

pll mov[4] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
vector<ll> v[50];
vector<ll> v2;
ll visited[50][50];
ll m, n;
ll idx;
ll remove_idx[5] = {0, 7, 3, 1, 5};
ll remove_inc[5] = {0, 15, 11, 9, 13};
ll num_cnt[5] = {0, 0, 0, 0, 0};

bool inmap(ll r, ll c) {
    return r >= 0 && r < n && c >= 0 && c < n;
}

void dfs(ll r, ll c) {
    visited[r][c] = 1;

    ll nx = r + mov[idx].first, ny = c + mov[idx].second;
    if (inmap(nx, ny) && visited[nx][ny] == 0) {
        v2.push_back(v[nx][ny]);
        dfs(nx, ny);
    }
    else {
        idx = (idx + 1) % 4;
        nx = r + mov[idx].first, ny = c + mov[idx].second;
        if (inmap(nx, ny) && visited[nx][ny] == 0) {
            v2.push_back(v[nx][ny]);
            dfs(nx, ny);
        }
    }
}

void remove_zero() {
    vector<ll> tmp;
    tmp.push_back(0);
    for (int i = 1; i < n * n; i++) {
        if (v2[i]) {
            tmp.push_back(v2[i]);
        }
    }
    while (tmp.size() < v2.size()) {
        tmp.push_back(0);
    }
    v2 = tmp;
}

ll exp() {
    ll cnt = 0;
    queue<ll> q;
    if (v2[1]) q.push(1);
    for (int i = 2; i < n * n; i++) {
        if (v2[i - 1] == v2[i]) {
            if (v2[i]) q.push(i);
        }
        else {
            if (q.size() >= 4) {
                num_cnt[v2[q.front()]] += q.size();
                cnt += q.size();
                while (!q.empty()) {
                    ll k = q.front();
                    q.pop();
                    v2[k] = 0;
                }
            }
            else {
                while (!q.empty()) {
                    q.pop();
                }
            }
            if (v2[i]) q.push(i);
        }
    }
    if (q.size() >= 4) {
        num_cnt[v2[q.front()]] += q.size();
        cnt += q.size();
        while (!q.empty()) {
            ll k = q.front();
            q.pop();
            v2[k] = 0;
        }
    }

    return cnt;
}

void change() {
    vector<ll> tmp;
    tmp.push_back(0);
    queue<ll> q;
    if (v2[1]) q.push(1);
    for (int i = 2; i < n * n; i++) {
        if (v2[i - 1] == v2[i]) {
            if (v2[i]) q.push(i);
        }
        else {
            if (q.size()) {
                if (tmp.size() < n * n) tmp.push_back(q.size());
                if (tmp.size() < n * n) tmp.push_back(v2[q.front()]);
                while (!q.empty()) {
                    q.pop();
                }
            }
            if (v2[i]) q.push(i);
        }
    }
    if (q.size()) {
        if (tmp.size() < n * n) tmp.push_back(q.size());
        if (tmp.size() < n * n) tmp.push_back(v2[q.front()]);
    }

    while (tmp.size() < v2.size()) {
        tmp.push_back(0);
    }
    v2 = tmp;
}

int main() {
    fastio;

    cin >> n >> m;

    for (int i = 0; i < n; i++) {
        v[i].resize(n);
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }

    v2.push_back(v[0][0]);
    dfs(0, 0);
    reverse(v2.begin(), v2.end());

    while (m--) {
        ll d, s;
        cin >> d >> s;

        ll inc = remove_inc[d];
        ll r_idx = remove_idx[d];
        for (int i = 0; i < s; i++) {
            v2[r_idx] = 0;
            r_idx += inc;
            inc += 8;
        }

        remove_zero();

        while (exp()) {
            remove_zero();
        }

        change();
    }

    cout << num_cnt[1] + 2 * num_cnt[2] + 3 * num_cnt[3];

    return 0;
}