#include <bits/stdc++.h>
using namespace std;

double ans = -1e18;

void dfs(double a[], int n) {
    if (n == 1) {
        ans = max(ans, a[0]);
        return;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            double b[4];
            int idx = 0;
            for (int k = 0; k < n; k++) if (k != i && k != j) b[idx++] = a[k];
            double results[4];
            int cnt = 0;
            results[cnt++] = a[i] + a[j];
            results[cnt++] = a[i] - a[j];
            results[cnt++] = a[i] * a[j];
            if (a[j] != 0) results[cnt++] = a[i] / a[j];
            for (int k = 0; k < cnt; k++) {
                b[idx] = results[k];
                dfs(b, n-1);
            }
        }
    }
}

int main() {
    double a[4];
    for (int i = 0; i < 4; i++) cin >> a[i];
    dfs(a, 4);
    cout << ans << endl;
}