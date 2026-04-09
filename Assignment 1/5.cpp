#include <bits/stdc++.h>
using namespace std;

void printOfSequence(int n) {
    if(n == 0) {
        return;
    }

    int elementOfSequence;
    cin >> elementOfSequence;

    printOfSequence(n - 1);

    cout << elementOfSequence << " ";
}

void solve() {
    int n; cin >> n;

    printOfSequence(n);
    
}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
}