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
    vi v(n);
    map<int, int> cnt;
    map<int, bool> vis;
    for (auto &x : v) {
        cin >> x;
        x %= m;
        cnt[x]++;
    }
    int ans = 0;
    for (auto &x : cnt) {
        if (vis[x.first])continue;
        int req = m - x.first;
        if (req == m) {
            req = 0;
        }
        if (req == x.first) {
            ans++;
            vis[req] = 1;
        } else if (cnt.count(req) == false) {
            ans += x.second;
            vis[x.first] = 1;
        } else {
            int mn = min(cnt[x.first], cnt[req]);
            int mx = max(cnt[x.first], cnt[req]);
            mx -= mn;
            if (mx > 0) {
                mx--;
            }
            ans++;
            ans += mx;
            vis[x.first] = 1;
            vis[req] = 1;
        }
    }
    cout << ans << endl;


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