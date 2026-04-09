#include <bits/stdc++.h>
using namespace std;

int sumOfSquares(int n) {
    if(n == 0) {
        return 0;
    }
    return n * n + sumOfSquares(n - 1);
}

void solve() {
    int n; cin >> n;

    cout << sumOfSquares(n) << "\n";
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
}

