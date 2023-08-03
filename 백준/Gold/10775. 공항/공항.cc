#include <iostream>
using namespace std;

int par[100005];
int cnt;

void init(int n) {
    for (int i = 1; i <= n; i++)
        par[i] = i;
}

int find(int a) {
    if (par[a] == a)
        return a;
    else
        return par[a] = find(par[a]);
}

void uni(int a, int b) {
    if (find(a) != find(b))
        par[find(a)] = find(b);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    int g, p;
    cin >> g >> p;

    init(g);

    for (int i = 0; i < p; i++) {
        int tmp;
        cin >> tmp;

        int val = find(tmp);
        if (val == 0)
            break;

        uni(val, val - 1);
        cnt++;
    }

    cout << cnt;

    return 0;
}