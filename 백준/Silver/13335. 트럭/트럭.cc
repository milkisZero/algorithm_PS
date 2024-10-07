
#include <bits/stdc++.h>
#define INF INT_MAX
#define LLINF LLONG_MAX
#define fastio ios::sync_with_stdio(0), cin.tie(NULL), cout.tie(NULL)
using namespace std;
using ll = long long;
using pi = pair<int, int>;
using pll = pair<ll, ll>;
using ull = unsigned long long;

queue<int> q;
queue<pair<int, int>> b;

int main() {
    fastio;
    int n, w, l, a, t = 0;

    cin >> n >> w >> l;

    for (int i = 0; i < n; i++) {
        cin >> a;
        q.push(a);
    }

    int curW = 0;

    while (!(q.empty() && b.empty())) {

        if (!b.empty() && (t - b.front().first >= w))
        {
            curW -= b.front().second;
            b.pop();
        }
        
        if(!q.empty() && curW + q.front() <= l){
            b.push({t, q.front()});
            curW += q.front();
            q.pop();
        }

        t++;
    }

    cout << t << endl;

    return 0;
}