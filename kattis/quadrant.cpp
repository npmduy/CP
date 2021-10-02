#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
typedef long long ll;
const int maxN = 1e6;

void solve() {
    int x, y;
    cin >> x >> y;
    if (x > 0 && y > 0) cout << 1;
    else if (x < 0 && y > 0) cout << 2;
    else if (x < 0 && y < 0) cout << 3;
    else if (x > 0 && y < 0) cout << 4;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
    solve();
    return 0;
}