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

const int N = 3e5 + 10;
vi adj[N];
map<int, int> cnt;

int fun(int root, int par) {
    vector<int> child;
    for (auto &val : adj[root]) {
        if (val != par) {
            child.pb(val);
        }
    }
    // for (auto &val : adj[root]) {
    //     cout << val << " ";
    // }
    // cout << endl;
    if (sz(child) == 0) {
        return 0;
    }
    if (sz(child) == 2) {
        int op1 = cnt[child[0]] + fun(child[1], root);
        int op2 = cnt[child[1]] + fun(child[0], root);
        return max(op1, op2);
    } else {
        int op1 = cnt[child[0]];
        return op1;
    }
}

int dfs(int root, vi &vis, int par) {
    vis[root] = 1;
    bool f = 0;
    for (auto &val : adj[root]) {
        if (val != par) {
            f = 1;
            break;
        }
    }
    if (f == 0) {
        return 0;
    }
    for (auto &child : adj[root]) {
        if (vis[child] == 0) {
            cnt[root] += (1 + dfs(child, vis, root));
        }
    }
    return cnt[root];
}

void Solve() {
    int n;
    cin >> n;
    if (n == 1) {
        cout << 0 << endl;
        return;
    }
    for (int i = 0; i < n - 1; i++) {
        int u, v;
        cin >> u >> v;
        u--; v--;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // for (int i = 0; i < n; i++) {
    //     cout << i << " -> ";
    //     for (auto &val : adj[i]) {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }

    vi vis(n, 0);
    int num = dfs(0, vis, -1);
    // for (int i = 0; i < n; i++) {
    //     cout << i << " -> " << cnt[i]  << endl;
    // }
    // cout << endl;
    int ans = fun(0, -1);
    cout << ans << endl;
    for (int i = 0; i < n; i++) {
        adj[i].clear();
        cnt[i] = 0;
        vis[i] = 0;
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