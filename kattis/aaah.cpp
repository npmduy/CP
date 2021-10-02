#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
typedef long long ll;
const int maxN = 1e6;

void solve() {
    string s1, s2;
    cin >> s1 >> s2;
    cout << (s1.size() >= s2.size() ? "go" : "no");
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
    solve();
    return 0;
}