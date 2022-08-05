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

    vector<vector<int>> ans(n);

    vi vis(n, 0);
    vector<vector<int>>row;
    vector<vector<int>>rowSorted;
    for (int i = 0; i < n; i++) {
        vi tmp(m);
        for (int j = 0; j < m; j++) {
            cin >> tmp[j];
        }
        row.pb(tmp);
        sort(all(tmp));
        rowSorted.pb(tmp);
    }
    vector<vector<int>>col;
    for (int i = 0; i < m; i++) {
        vi tmp(n);
        for (int j = 0; j < n; j++) {
            cin >> tmp[j];
        }
        col.pb(tmp);
    }
    vector<vector<int>> orderedRow(n);
    for (int i = 0; i < n; i++) {
        vi tmp;
        for (int j = 0; j < m; j++) {
            tmp.pb(col[j][i]);
        }
        sort(all(tmp));
        for (int j = 0; j < n; j++) {
            if (vis[j] == 0) {
                if (rowSorted[j] == tmp) {
                    vis[j] = 1;
                    ans[i] = row[j];
                    break;
                }
            }
        }
    }
    for (int i = 0; i < n; i++) {
        for (auto &x : ans[i]) {
            cout << x << " ";
        }
        cout << endl;
    }

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