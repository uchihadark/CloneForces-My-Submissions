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

vi adj[4];


void dfs(int v, vi& vis) {
    vis[v] = 1;
    for (auto &x : adj[v]) {
        if (x != 0) {
            if (vis[x] == 0) {
                dfs(x, vis);
            }
        } else {
            return;
        }
    }
}

void Solve() {
    int x;
    cin >> x;
    int a, b, c;
    cin >> a >> b >> c;
    adj[1].pb(a);
    adj[2].pb(b);
    adj[3].pb(c);

    vi vis(4, 0);
    dfs(x, vis);
    for (int i = 1; i < 4; i++) {
        if (vis[i] == 0) {
            cout << "NO\n";
            adj[1].clear();
            adj[2].clear();
            adj[3].clear();
            return;
        }
    }
    cout << "YES\n";
    adj[1].clear();
    adj[2].clear();
    adj[3].clear();

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