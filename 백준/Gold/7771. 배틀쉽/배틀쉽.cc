#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
using ll = long long;

int arr[12][12];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int maxi = -1, x = 1, y = 1;
    for (int i = 0; i <= 11; i++) {
        for (int j = 0; j <= 11; j++) {
            if (i == 0 || j == 0 || i == 11 || j == 11) {
                arr[i][j] = -2;
                continue;
            }

            cin >> arr[i][j];
            if (maxi < arr[i][j]) {
                maxi = arr[i][j];
                x = i;
                y = j;
            }
        }
    }

    arr[x][y] = -1;

    int s[5] = {1, 2, 3, 3};
    int idx = 0;
    for (int i = 1; i < 11; i++) {
        for (int j = 1; j < 11; j++) {
            if (arr[i][j] == -1 || idx == 4)
                continue;

            int mv = 4 - idx;
            int check = 0;
            for (int k = i - 1; k <= i + 1; k++) {
                for (int q = j - 1; q <= j + mv; q++) {
                    if (arr[k][q] == -1) {
                        check = 1;
                        break;
                    }
                    else if (k == i && (q >= j && q < j + mv) && arr[k][q] == -2) {
                        check = 1;
                        break;
                    }
                }
            }

            if (!check) {
                for (int k = j; k < j + mv; k++) {
                    arr[i][k] = -1;
                }
                s[idx]--;
                if (!s[idx])
                    idx++;
                continue;
            }

            check = 0;
            for (int k = i - 1; k <= i + mv; k++) {
                for (int q = j - 1; q <= j + 1; q++) {
                    if (arr[k][q] == -1) {
                        check = 1;
                        break;
                    }
                    else if (q == j && (k >= i && k < i + mv) && arr[k][q] == -2) {
                        check = 1;
                        break;
                    }
                }
            }

            if (!check) {
                for (int k = i; k < i + mv; k++) {
                    arr[k][j] = -1;
                }
                s[idx]--;
                if (!s[idx])
                    idx++;
                continue;
            }
        }
    }

    for (int i = 1; i < 11; i++) {
        for (int j = 1; j < 11; j++) {
            if (arr[i][j] == -1)
                cout << '#';
            else
                cout << '.';
        }
        cout << '\n';
    }

    return 0;
}