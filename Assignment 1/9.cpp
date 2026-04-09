#include <bits/stdc++.h>
using namespace std;    

void generate(string s, int pos) {
    if(pos == s.size()) {
        cout << s << "\n";
        return;
    }

    for(int i = pos; i < s.size(); i++) {
        swap(s[pos], s[i]);
        generate(s, pos + 1);
        swap(s[pos], s[i]);
    }
}

void solve() {
    string s; cin >> s;

    generate(s, 0);

}

int main() {
    int t = 1;
    while(t--) {
        solve();
    }
}