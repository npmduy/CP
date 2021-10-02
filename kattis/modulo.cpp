#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
typedef long long ll;
const int maxN = 1e6;
int a[10], n = 10;

void readData() {
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

void solve() {
    bool cnt[42] = {0};
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ans += (cnt[a[i] % 42] == 0);
        cnt[a[i] % 42] = 1;
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
    readData();
    solve();
    return 0;
}
