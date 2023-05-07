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
	vector<vector<int>>adj(n + 1);
	map<int, int> degree;
	int mn = inf;
	for (int i = 0; i < m; i++) {
		int v, u;
		cin >> v >> u;
		adj[u].pb(v);
		adj[v].pb(u);
		degree[u]++;
		degree[v]++;
	}

	queue<int> q;
	vector<int> vis(n + 1, 0);

	for (auto &x : degree) {
		if (x.second == 1) {
			vis[x.first] = 1;
			q.push(x.first);
		}
	}
	vector<int> seq;
	int centre = -1;
	while (q.empty() == false) {
		int s = sz(q);

		for (int i = 0; i < s; i++) {
			int cur = q.front();
			q.pop();
			degree[cur]--;
			for (auto &x : adj[cur]) {
				if (vis[x] == 0) {
					degree[x]--;
				}
			}
		}

		queue<int> q2;
		for (auto &x : degree) {
			if (x.second == 1) {
				vis[x.first] = 1;
				q2.push(x.first);
			}
		}
		if (sz(q2) == 0) {
			for (auto &x : degree) {
				if (vis[x.first] == 0) {
					centre = x.first;
					break;
				}
			}
		}
		q = q2;
	}
	int x, y;
	x = sz(adj[centre]);
	int child = adj[centre][0];
	y = sz(adj[child]) - 1;
	cout << x << " " << y << endl;
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