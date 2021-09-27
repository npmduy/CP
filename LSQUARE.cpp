#include <bits/stdc++.h>
using namespace std;

struct Point {
    int x, y;
};

#define ln '\n'
typedef long long ll;
const int maxN = 1e6;
Point a[maxN];
int n;

void readData() {
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> a[i].x >> a[i].y;
}

bool cmp(Point p1, Point p2) { // smaller
    return (p1.x < p2.x || (p1.x == p2.x && p1.y < p2.y));
}

bool BS(int lo, int hi, Point p) {
    int m;
    while (lo <= hi) {
        m = (lo+hi)/2;
        if (a[m].x == p.x && a[m].y == p.y) return true;
        if (cmp(a[m], p)) lo = m+1;
        else hi = m-1;
    }
    return false;
}

void solve() {
    sort(a, a+n, cmp);
    bool isExist1 = 0, isExist2 = 0;
    int canhLN = -1;
    Point ans; ans.x = -1; ans.y = -1;
    for (int i = 0; i < n; ++i) {
        int j = i+1;
        while (a[j].x == a[i].x && j < n) {
            int canh = a[j].y - a[i].y;
            Point u; u.x = a[j].x + canh; u.y = a[j].y;
            Point v; v.x = a[i].x + canh; v.y = a[i].y;
            isExist1 = BS(j+1, n-1, u);
            isExist2 = BS(j+1, n-1, v);
            if (isExist1 && isExist2 && canh > canhLN) ans = a[i], canhLN = canh;
            ++j;
        }
    }
    if (canhLN == -1) cout << -1;
    else cout << ans.x << ' ' << ans.y;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("LSQUARE.inp", "r", stdin);
    freopen("LSQUARE.out", "w", stdout);
    readData();
    solve();
    return 0;
}