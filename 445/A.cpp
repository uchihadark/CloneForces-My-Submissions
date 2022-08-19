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
    int n, m;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < n; i++) {
        char cur;
        if (i % 2 == 0) {
            cur = 'W';
        } else {
            cur = 'B';
        }
        for (int j = 0; j < m; j++) {
            if (s[i][j] != '-') {
                s[i][j] = cur;
            }
            if (cur == 'W') {
                cur = 'B';
            } else {
                cur = 'W';
            }
        }
    }

    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }
}

int32_t main() {
    FAST_IO
    int TC = 1;
    // cin >> TC;
    while (TC--) {
        Solve();
    }
    TIME
}