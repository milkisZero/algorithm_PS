#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    for (int i = 1; i <= 1000000; i++) {
        int q = i, sum = 0;
        while (q) {
            sum += q % 10;
            q /= 10;
        }

        if (sum + i == n) {
            cout << i;
            return 0;
        }
    }
    cout << 0;

    return 0;
}