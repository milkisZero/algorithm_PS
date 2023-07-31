#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int par[100005], n;

typedef struct info_star {
    int x, y, z;
    int num;
} info;
info stars[100005];

struct edge {
    int a, b;
    int cost;
    bool operator<(const edge &o) const {
        return cost < o.cost;
    }
};
vector<edge> _edges;

void init() {
    for (int i = 0; i <= n; i++)
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
        par[find(b)] = find(a);
}

int kruskal() {
    int ret = 0;
    init();
    sort(_edges.begin(), _edges.end());
    for (int i = 0; i < _edges.size(); i++) {
        edge e = _edges[i];
        if (find(e.a) != find(e.b)) {
            uni(e.a, e.b);
            ret += e.cost;
        }
    }
    return ret;
}

int cmp_x(info a, info b) {
    if (a.x < b.x)
        return 1;
    else
        return 0;
}
int cmp_y(info a, info b) {
    if (a.y < b.y)
        return 1;
    else
        return 0;
}
int cmp_z(info a, info b) {
    if (a.z < b.z)
        return 1;
    else
        return 0;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> stars[i].x >> stars[i].y >> stars[i].z;
        stars[i].num = i;
    }

    sort(stars, stars + n, cmp_x);
    for (int i = 0; i < n - 1; i++) {
        int val = abs(stars[i].x - stars[i + 1].x);
        _edges.push_back({stars[i].num, stars[i + 1].num, val});
    }

    sort(stars, stars + n, cmp_y);
    for (int i = 0; i < n - 1; i++) {
        int val = abs(stars[i].y - stars[i + 1].y);
        _edges.push_back({stars[i].num, stars[i + 1].num, val});
    }

    sort(stars, stars + n, cmp_z);
    for (int i = 0; i < n - 1; i++) {
        int val = abs(stars[i].z - stars[i + 1].z);
        _edges.push_back({stars[i].num, stars[i + 1].num, val});
    }

    cout << kruskal();

    return 0;
}