#include <bits/stdc++.h>
using namespace std;

int powerSum(int b, int n) {
    if(n == 0) {
        return 1;
    }

    return pow(b, n) + powerSum(b, n - 1);
}

void solve() {
    int b, n; cin >> b >> n;

    cout << powerSum(b, n) << "\n";
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    } 
}