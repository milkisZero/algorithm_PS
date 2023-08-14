#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using ll = long long;

priority_queue<ll, vector<ll>, greater<>> pq;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    ll maxi = -1;
    for (int i = 0; i < n; i++) {
        ll tmp;
        cin >> tmp;
        pq.push(tmp);
        maxi = max(maxi, tmp);
    }

    ll res = maxi - pq.top();
    ll limit = maxi;
    while (1) {
        ll tmp = pq.top();
        pq.pop();

        res = min(maxi - tmp, res);
        if (limit == tmp)
            break;
        tmp *= 2;

        maxi = max(maxi, tmp);
        pq.push(tmp);
    }

    cout << res;

    return 0;
}