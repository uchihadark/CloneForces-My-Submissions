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

int node = 0;

bool dfs(int v, vector<int>&vis, vector<set<int>>&adj, int par) {
	vis[v] = 1;
	for (auto &x : adj[v]) {
		if (vis[x] == false) {
			if (dfs(x, vis, adj, v))return true;
		} else if (x != par)return true;
	}
	return false;
}

void Solve() {
	int n;
	cin >> n;
	vi v(n);
	for (auto &x : v) {
		cin >> x;
	}
	vector<set<int>>adj(n + 1);
	for (int i = 0; i < n; i++) {
		adj[i + 1].insert(v[i]);
		adj[v[i]].insert(i + 1);
	}
	vector<int>deg2;
	for (int i = 1; i <= n; i++) {
		if (sz(adj[i]) == 2) {
			deg2.push_back(i);
		}
	}

	int cycle = 0;
	int noncycle = 0;

	vector<int> vis(n + 1, 0);
	for (auto &x : deg2) {
		if (vis[x] == 0) {
			bool check = dfs(x, vis, adj, -1);
			if (check)cycle++;
			else {
				noncycle++;
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (vis[i] == 0) {
			bool check = dfs(i, vis, adj, -1);
			if (check)cycle++;
			else {
				noncycle++;
			}
		}
	}

	int mx = cycle + noncycle;
	int mn = cycle + min(noncycle, 1LL);
	cout << mn << " " << mx << endl;

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