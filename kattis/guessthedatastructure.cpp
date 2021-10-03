#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
typedef long long ll;
const int maxN = 1e6;
stack<int> s;
queue<int> q;
priority_queue<int> pq;
bool check[3];
int n;
pair<int, int> a[maxN];
string strutures[] = {"stack", "queue", "priority queue"};

void readData() {
    for (int i = 0; i < n; ++i)
        cin >> a[i].first >> a[i].second;
}

void solve() {
    memset(check, 1, 3);
    while (!s.empty())
        s.pop();
    while (!q.empty())
        q.pop();
    while (!pq.empty())
        pq.pop();
    for (int i = 0; i < n; ++i) {
        if (a[i].first == 1) {
            s.push(a[i].second);
            q.push(a[i].second);
            pq.push(a[i].second);
        } else {
            if (s.empty()) check[0] = 0;
            else {
                int s_top = s.top();
                check[0] &= s_top == a[i].second;
                s.pop();
            }
            if (q.empty()) check[1] = 0;
            else {
                int q_top = q.front();
                check[1] &= q_top == a[i].second;
                q.pop();
            }
            if (pq.empty()) check[2] = 0;
            else {
                int pq_top = pq.top();
                check[2] &= pq_top == a[i].second;
                pq.pop();
            }
        }
    }
    int cnt = 0, ans = -1;
    for (int i = 0; i < 3; ++i) {
        ans = (check[i] == 1 ? i : ans);
        cnt += (check[i] == 1);
    }
    if (cnt == 0) cout << "impossible";
    else if (cnt == 1) cout << strutures[ans];
    else cout << "not sure";
    cout << ln;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    while (cin >> n) {
        readData();
        solve();
    }
    return 0;
}