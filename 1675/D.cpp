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

const int N = 2e5 + 5;
vi adj[N];
vi vis(N, 0);
void dfs(int v, vector<int>&path, vector<vector<int>> &ans) {
    vis[v] = 1;
    path.pb(v);
    if (sz(adj[v]) == 1 && vis[adj[v][0]]) {
        ans.pb(path);
    } else {
        int ind = -1;
        for (int i = 0; i < sz(adj[v]); i++) {
            if (vis[adj[v][i]] == 0) {
                dfs(adj[v][i], path, ans);
                ind = i;
                break;
            }
        }
        if (ind != -1) {
            for (int i = ind + 1; i < sz(adj[v]); i++) {
                if (vis[adj[v][i]] == 0) {
                    path.clear();
                    dfs(adj[v][i], path, ans);
                }
            }
        }
    }

}


void Solve() {
    int n;
    cin >> n;
    vi v(n);
    for (int i = 0; i < n; i++) {
        vis[i] = 0;
    }
    for (int i = 0; i < n; i++) {
        adj[i].clear();
    }
    int root;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        v[i]--;
        if (v[i] == i) {
            root = i;
            continue;
        } else {
            adj[v[i]].pb(i);
            adj[i].pb(v[i]);
        }
    }
    if (n == 1) {
        cout << 1 << endl;
        cout << 1 << endl;
        cout << 1 << endl;

        cout << endl;
        return;
    }
    vector<vector<int>>ans;
    vi path;
    // for (int i = 0; i < n; i++) {
    //     cout << i << " - > ";
    //     for (auto &val : adj[i]) {
    //         cout << val << " ";
    //     }
    //     cout << endl;
    // }
    // cout << endl;
    dfs(root, path, ans);

    cout << sz(ans) << endl;
    for (int i = 0; i < sz(ans); i++) {
        cout << sz(ans[i]) << endl;
        for (auto &val : ans[i]) {
            cout << val + 1 << " ";
        }
        cout << endl;
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