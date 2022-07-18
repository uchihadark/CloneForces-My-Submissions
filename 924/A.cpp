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

bool check(vi& row, vi& col, vector<string> &s) {
    for (int i = 0; i < sz(row); i++) {
        for (int j = 0; j < sz(col); j++) {
            if (s[row[i]][col[j]] != '#') {
                return false;
            }
        }
    }
    return true;
}

void Solve() {
    int n, m;
    cin >> n >> m;
    vector<string> s(n);
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == '#') {
                vi row, col;
                for (int k = 0; k < m; k++) {
                    if (s[i][k] == '#') {
                        col.pb(k);
                    }
                }
                for (int k = 0; k < n; k++) {
                    if (s[k][j] == '#') {
                        row.pb(k);
                    }
                }
                if (check(row, col, s) == false) {
                    cout << "NO\n";
                    return;
                }
            }
        }
    }
    cout << "YES\n";
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