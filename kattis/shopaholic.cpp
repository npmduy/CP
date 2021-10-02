#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
typedef long long ll;
const int maxN = 1e6;
ll n, a[maxN];

void readData()
{
    cin >> n;
    for (ll i = 0; i < n; ++i)
        cin >> a[i];
}

void solve()
{
    sort(a, a + n, greater<int>());
    ll ans = 0;
    for (ll i = 2; i < n; i += 3)
        ans += a[i];
    cout << ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    //freopen("input.inp", "r", stdin);
    //freopen("output.out", "w", stdout);
    readData();
    solve();
    return 0;
}