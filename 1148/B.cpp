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
    int n, m, ta, tb, k;
    cin >> n >> m >> ta >> tb >> k;
    vi a(n), b(m);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        cin >> b[i];
    }
    if (k >= n || k >= m) {
        cout << -1 << endl;
        return;
    }
    bool f = 1;
    vi v(n), v2(m);
    for (int i = 0; i < n; i++) {
        v[i] = a[i] + ta;
    }
    for (int i = 0; i < m; i++) {
        v2[i] = b[i] + tb;
    }
    int ans = -1;
    for (int i = 0; i <= k; i++) {
        int rem = k - i;
        int num = v[i];
        auto it = lower_bound(all(b), num);
        if (it == b.end()) {
            cout << -1 << endl;
            return;
        }
        int ind = it - b.begin();
        ind += rem;
        if (ind >= sz(b)) {
            cout << -1 << endl;
            return;
        } else {
            ans = max(ans, v2[ind]);
        }
    }
    cout << ans << endl;

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