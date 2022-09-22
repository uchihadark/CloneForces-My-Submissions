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
    for (auto &x : v) {
        cin >> x;
    }
    if (n <= 2) {
        cout << 0 << endl;
        return;
    }
    int ans = inf;
    vi a, b;
    a.pb(v[0] - 1);
    a.pb(v[0]);
    a.pb(v[0] + 1);

    b.pb(v[1] - 1);
    b.pb(v[1]);
    b.pb(v[1] + 1);

    for (int i = 0; i < sz(a); i++) {
        for (int j = 0; j < sz(b); j++) {
            int cur = 0;
            if (i != 1) {
                cur++;
            }
            if (j != 1) {
                cur++;
            }
            bool f = 1;
            int diff = a[i] - b[j];
            int pre = b[j];
            for (int k = 2; k < n; k++) {
                if (pre - v[k] == diff) {
                    pre = v[k];
                    continue;
                } else {
                    if (pre - (v[k] + 1) == diff) {
                        cur++;
                        pre = v[k] + 1;
                    } else if (pre - (v[k] - 1) == diff) {
                        cur++;
                        pre = v[k] - 1;
                    } else {
                        f = 0;
                        break;
                    }
                }
            }
            if (f) {
                ans = min(ans, cur);
            }
        }

    }
    if (ans == inf) {
        cout << -1 << endl;
    } else {
        cout << ans << endl;
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