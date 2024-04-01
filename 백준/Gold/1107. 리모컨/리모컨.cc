#include <iostream>
#include <vector>
using namespace std;

int control[10];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(NULL); cout.tie(NULL);
	
	int d;
	cin >> d;

	int n, tmp;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		control[tmp] = 1;
	}

	int q = 0;
	pair<int, int> res = make_pair(-1,0);
	while (1) {
		int a = q, b, cnt = 0, chk = 0;
		do {
			b = a % 10;
			a = a / 10;
			cnt++;

			if (control[b]) {
				chk = 1;
				break;
			}
		} while (a);

		if (!chk && (abs(res.first - d) > abs(d - q) || res.first == -1)) {
			res.first = q;
			res.second = cnt;
		}
		q++;

		if (q > 1000000)
			break;
	}

	if (res.first == -1 || res.second + abs(d - res.first) > abs(100 - d))
		cout << abs(100 - d);
	else
		cout << res.second + abs(d - res.first);

	return 0;
}