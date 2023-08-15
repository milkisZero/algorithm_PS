#include <iostream>
#include <string>
using namespace std;

int main() {
    string a;
    cin >> a;

    int sum = 0;
    while (a.find(',') != string::npos) {
        int deli = a.find(',');
        string tmp = a.substr(0, deli);

        a = a.substr(deli + 1);
        sum += stoi(tmp);
    }

    cout << sum + stoi(a);

    return 0;
}