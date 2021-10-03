#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
typedef long long ll;
const int maxN = 1e6;
int n, a[maxN];

void readData() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
}

void solve() {
    int leftmax[n], rightmin[n];
    leftmax[0] = a[0];
    for (int i = 1; i < n; ++i)
        leftmax[i] = max(a[i], leftmax[i-1]);
    rightmin[n-1] = a[n-1];
    for (int i = n-2; i >= 0; --i)
        rightmin[i] = min(a[i], rightmin[i+1]);
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        if (i == 0 && a[i] <= rightmin[i+1]) cnt++;
        else if (i == n-1 && a[i] >= leftmax[i-1]) ++cnt;
        else if (a[i] >= leftmax[i-1] && a[i] <= rightmin[i+1]) cnt++;
    }
    cout << cnt;
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