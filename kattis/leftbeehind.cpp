#include <bits/stdc++.h>
using namespace std;

#define ln '\n'

int main() {
    int a, b;
    while (cin >> a && cin >> b) {
        if (a == 0 && b == 0) break;
        if (a + b == 13) cout << "Never speak again." << ln;
        else if (a < b) cout << "Left beehind." << ln;
        else if (a > b) cout << "To the convention." << ln;
        else cout << "Undecided." << ln;
    }
    return 0;
}