#include <iostream>
using namespace std;

void make_case(char c[][9], char a, char b) {

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			if (i % 2 == 0) {
				if (j % 2 == 0) {
					c[i][j] = a;
				}
				else
					c[i][j] = b;
			}
			else {
				if (j % 2 != 0) {
					c[i][j] = a;
				}
				else
					c[i][j] = b;

			}
		}
	}
}

int cnt(int n, int m, char str[][55], char c[][9]) {
	int cnt = 0;
	int idx1 = 0, idx2 = 0;
	int res = -1;
	for (int i = 0; i < n - 7; i++) {
		for (int k = 0; k < m - 7; k++) {
			for (int j = i; j < i + 8; j++) {
				for (int l = k; l < k + 8; l++) {
					if (str[j][l] != c[idx1][idx2])
						cnt++;
					idx2++;
				}
				idx1++;
				idx2 = 0;
			}
			if (res > cnt || res == -1)
				res = cnt;
			//cout << cnt << '\n';
			cnt = 0;
			idx1 = 0; idx2 = 0;
		}
	}
	return res;
}

int main() {
	int n, m;
	cin >> n >> m;

	char case_1[9][9] = { "" };
	char case_2[9][9] = { "" };
	char str[55][55] = {""};
	for (int i = 0; i < n; i++) {
		cin >> str[i];
	}

	make_case(case_1, 'W', 'B');
	make_case(case_2, 'B', 'W');

	int res1 = cnt(n, m, str, case_1);
	int res2 = cnt(n, m, str, case_2);

	if (res1 < res2)
		cout << res1 << '\n';
	else
		cout << res2 << '\n';

	return 0;
}