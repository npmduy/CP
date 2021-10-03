#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
typedef long long ll;
const int maxN = 1e6;
priority_queue<int> leftt;
priority_queue<int, vector<int>, greater<int>> rightt;

void add(int n) {
    if (leftt.empty()) 
        leftt.push(n);
    else if (n > leftt.top()) {
        rightt.push(n);
        if (rightt.size() > leftt.size()) {
            leftt.push(rightt.top());
            rightt.pop();
        }
    } else {
        leftt.push(n);
        if (leftt.size() > rightt.size()+1) {
            rightt.push(leftt.top());
            leftt.pop();
        }
    }
}

int getMid() {
    if (leftt.size() == rightt.size()) {
        int res = rightt.top();
        rightt.pop();
        return res;
    } else {
        int res = leftt.top();
        leftt.pop();
        return res;
    }
}

int toInt(string s) {
    int res = 0;
    for (int i = 0; i < s.size(); ++i)
        res = res*10 + (int)(s[i]-'0');
    return res; 
}

void solve() {
    string s;
    while (cin >> s) {
        if (*s.begin() == '#') 
            cout << getMid() << ln;
        else 
            add(toInt(s));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.inp", "r", stdin);
    // freopen("output.out", "w", stdout);
    solve();
    return 0;
}