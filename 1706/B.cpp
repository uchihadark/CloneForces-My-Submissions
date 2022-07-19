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
    int n;
    cin >> n;
    vi v(n);
    map<int, vi> cnt;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        cnt[v[i]].pb(i + 1);
    }
    vi ans(n, 0);
    for (int i = 1; i <= n; i++) {
        int cur = 0;
        if (sz(cnt[i]) > 0) {
            cur++;
            int last = cnt[i][0];
            for (int j = 1; j < sz(cnt[i]); j++) {
                int diff = cnt[i][j] - last;
                if (diff & 1) {
                    last = cnt[i][j];
                    cur++;
                }
            }
        }
        ans[i - 1] = cur;
    }
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << endl;
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