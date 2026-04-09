#include <bits/stdc++.h>
using namespace std;

int sumOfDigits(int n) {
    if(n == 0) {
        return 0;
    }

    return n + sumOfDigits(n - 1);
}

void solve() {
    int n; cin >> n;

    cout << sumOfDigits(n) << "\n";
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
}