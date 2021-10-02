#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
typedef long long ll;
const int maxN = 1e6;

struct clocktime {
    int hh, mm;
    int period;
} a[maxN];
int n;

void readData() {
    char sthuseless;
    string p;
    for (int i = 0; i < n; ++i) {
        cin >> a[i].hh >> sthuseless >> a[i].mm;
        cin >> p;
        a[i].period = (p == "a.m." ? 0 : 1);
        if (a[i].hh == 12 && p == "a.m.") a[i].hh = 0;
        if (a[i].hh == 12 && p == "p.m.") a[i].hh = 0;
        //cout << a[i].period << ln;
    }
}

bool cmp(clocktime t1, clocktime t2) {
    return ((t1.period < t2.period) ||
            (t1.period == t2.period && t1.hh < t2.hh) ||
            (t1.period == t2.period && t1.hh == t2.hh && t1.mm < t2.mm));
}

void solve() {
    sort(a, a+n, cmp);
    int min;
    string am = "a.m.", pm = "p.m.";
    for (int i = 0; i < n; ++i) {
        if (a[i].hh == 0) cout << "12:";
        else cout << a[i].hh << ':';
        if (a[i].mm / 10 == 0)
            cout << 0 << a[i].mm;
        else cout << a[i].mm;
        cout << ' ' << (a[i].period == 0 ? am : pm) << ln;
    }
    cout << ln;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (true) {
        cin >> n;
        if (n == 0) break;
        readData();
        solve();
    }
    return 0;
}