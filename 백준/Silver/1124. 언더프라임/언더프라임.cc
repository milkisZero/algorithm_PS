#include <iostream>
using namespace std;

int prime[100005];
int length[100005];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(NULL), cout.tie(NULL);

    int a, b;
    cin >> a >> b;

    prime[0] = prime[1] = 1;
    for (int i = 2; i <= b; i++) {
        if (prime[i])
            continue;
        else
            length[i]++;
        for (int j = 2; j * i <= b; j++) {
            prime[i * j] = 1;
        }
    }

    for (int i = 2; i <= b; i++) {
        for (int j = 2; j * i <= b; j++) {
            length[i * j] = max(length[i * j], length[i] + length[j]);
        }
    }

    int cnt = 0;
    for (int i = a; i <= b; i++) {
        if (!prime[length[i]])
            cnt++;
    }

    cout << cnt;

    return 0;
}