#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
typedef long long ll;
const int maxN = 1e6;

void solve() {
    int h, m;
    cin >> h >> m;
    int ans = h*60 + m - 45;
    if (ans < 0) cout << 23 << ' ' << 60 + ans;
    else cout << ans / 60 << ' ' << ans % 60;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
    solve();
    return 0;
}