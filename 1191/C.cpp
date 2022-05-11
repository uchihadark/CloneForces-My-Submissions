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
    int n, k, m;
    cin >> n >> m >> k;
    vi v(m);
    for (int i = 0; i < m; i++) {
        cin >> v[i];
    }
    if (k == 1) {
        cout << m << endl;
        return;
    }
    int ans = 0;
    int r = k;
    int pre = -1;
    while (pre != m - 1) {
        int cnt = 0;
        auto it = upper_bound(all(v), r);
        int curInd = it - v.begin();
        curInd--;
        if (curInd > pre) {
            int cnt = curInd - pre;
            r += cnt;
            pre = curInd;
            ans++;
        } else {
            int x = (v[pre + 1] - r) / k + ((v[pre + 1] - r) % k != 0);
            r += k * x;
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