#include <iostream>
#include <math.h>
using namespace std;

int cnt[10];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int n;
    cin >> n;

    int k = n;
    for (int j = 0; k; j++) {
        int tmp = k % 10;
        k /= 10;

        for (int i = 0; i < 10; i++) {
            if (i == tmp) {
                cnt[i] += n % (int)round(pow(10, j)) + 1;
                if (tmp == 0)
                    cnt[i] += round(pow(10, j)) * (k - 1);
                else
                    cnt[i] += round(pow(10, j)) * k;
            }
            else if (tmp < i || i == 0) {
                cnt[i] += round(pow(10, j)) * k;
            }
            else if (i < tmp) {
                cnt[i] += round(pow(10, j)) * (k + 1);
            }
        }
    }

    for (int i = 0; i < 10; i++) {
        cout << cnt[i] << ' ';
    }

    return 0;
}