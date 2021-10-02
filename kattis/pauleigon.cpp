#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
typedef long long ll;
const int maxN = 1e6;
int n, p, q;

void readData() {
    cin >> n >> p >> q;
}

void solve() {
    cout << (((p+q)/n) % 2 == 0 ? "paul" : "opponent");
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