#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int par[1000005], n;

struct edge {
	int a, b, cost;
	bool operator<(const edge& o)const {
		return cost < o.cost;
	}
};

vector<edge> _edges;
vector<edge> selected;

void init() {
	for (int i = 0; i <= n; i++) {
		par[i] = i;
	}
}
int find(int a) {
	if (par[a] == a)
		return a;
	else {
		par[a] = find(par[a]);
		return par[a];
	}
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
			selected.push_back(e);
			ret += e.cost;
		}
	}
	return ret;
}
int main(){
	int e;
	cin >> n >> e;

	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		_edges.push_back({a,b,c});
	}

	cout << kruskal();

	return 0;
}