#include <bits/stdc++.h>
const long long mod = 1e9 + 7;
#define int long long
#define pi pair<int,int>
#define vi vector<int>
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define pb push_back
#define mp make_pair
#define FAST_IO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define TIME cerr << "\n" << (float)clock() / CLOCKS_PER_SEC * 1000 << " ms" << endl;
#define DEBUG(x) cout << '>' << #x << ':' << x << endl;
#define mem(x,val) memset((x),(val),sizeof(x))
#define inf      1e18
#define endl    "\n"
using namespace std;

void Solve() {
    string s;
    cin >> s;
    bool b = 0, a = 0;
    for (int i = 0; i < sz(s); i++) {
        if (s[i] == 'B') {
            b = 1;
        } else {
            a = 1;
        }
    }
    int n = sz(s);
    if (a == 0 || b == 0) {
        cout << "NO\n";
        return;
    }
    if (s[0] == 'B' || s[n - 1] == 'A') {
        cout << "NO\n";
        return;
    }
    vi aa(n, 0);
    vi bb(n, 0);
    aa[0] = 1;
    for (int i = 1; i < n; i++) {
        if (s[i] == 'A') {
            aa[i] += aa[i - 1] + 1;
        } else {
            aa[i] = aa[i - 1];
        }
    }
    for (int i = 1; i < n; i++) {
        if (s[i] == 'B') {
            bb[i] += bb[i - 1] + 1;
        } else {
            bb[i] = bb[i - 1];
        }
    }
    for (int i = 0; i < n; i++) {
        if (bb[i] > aa[i]) {
            cout << "NO\n";
            return;
        }
        // cout << bb[i] << " " << aa[i] << endl;
    }
    cout << "YES\n";
}

int32_t main() {
    FAST_IO
    int TC = 1;
    cin >> TC;
    while (TC--) {
        Solve();
    }
    TIME
}