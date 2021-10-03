#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
typedef long long ll;
const int maxN = 1e6;
pair<string, int> a[maxN];
int n;

void readData() {
    for (int i = 0; i < n; ++i) {
        cin >> a[i].first;
        a[i].second = i;
    }
}

bool cmp(pair<string, int> s1, pair<string, int> s2) {
    return ((s1.first[0] < s2.first[0]) ||
            (s1.first[0] == s2.first[0] && s1.first[1] < s2.first[1]) ||
            (s1.first[0] == s2.first[0] && s1.first[1] == s2.first[1] && s1.second < s2.second));
}

void solve() {
    sort(a, a+n, cmp);
    for (int i = 0; i < n; ++i)
        cout << a[i].first << ln;
    cout << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.inp", "r", stdin);
    // freopen("output.out", "w", stdout);
    while (true) {
        cin >> n;
        if (n == 0) break;
        readData();
        solve();
    }
    return 0;
}