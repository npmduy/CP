#include <bits/stdc++.h>
using namespace std;

#define ln '\n'
typedef long long ll;
const int maxN = 1e6;
string brackets;

void readData() {
    cin >> brackets;
}

bool isValid(char c1, char c2) {
    return ((c1 == '[' && c2 == ']') || (c1 == '{' && c2 == '}') || (c1 == '(' && c2 == ')'));
}

bool check() {
    stack<char> s;
    for (int i = 0; i < brackets.size(); ++i) {
        if (brackets[i] == '(' || brackets[i] == '[' || brackets[i] == '{')
            s.push(brackets[i]);
        else if (s.empty()) return false;
        else if (isValid(s.top(), brackets[i])) s.pop();
        else return false;
    }
    return s.empty();
}

void solve() {
    cout << (check() ? "TRUE" : "FALSE");
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