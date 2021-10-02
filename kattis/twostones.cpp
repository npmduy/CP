#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
typedef long long ll;
const int maxN = 1e6;

void solve() {
    int n;
    cin >> n;
    cout << ((n % 2 == 0) ? "Bob" : "Alice");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
    solve();
    return 0;
}