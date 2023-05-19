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

int ans = 0;

int dfs(int v, vector<int>&vis, int par, vector<vector<int>>&adj) {
	vis[v] = 1;
	int cur = 1;
	for (auto &x : adj[v]) {
		if (vis[x] == 0) {
			cur += dfs(x, vis, v, adj);
		}
	}
	if (cur % 2 == 0 && par != -1)ans++;
	return cur;
}

void Solve() {
	int n;
	cin >> n;
	if (n & 1) {
		cout << -1 << endl;
		return;
	}
	vector<vector<int>>adj(n + 1);

	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adj[u].pb(v);
		adj[v].pb(u);
	}


	vector<int> vis(n + 1, 0);
	dfs(1, vis, -1, adj);

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