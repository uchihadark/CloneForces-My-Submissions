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

int cntNodes = 0;
int cycle = 0;

void dfs(int v, vector<vector<int>>&adj, vector<int>&len) {
	cntNodes++;
	len[v] = cntNodes;
	for (auto &x : adj[v]) {
		if (len[x] == -1) {
			dfs(x, adj, len);
		} else {
			cycle = len[v] - len[x] + 1;
		}
	}
}

void Solve() {
	int n;
	cin >> n;
	vi v(n);
	vector<vector<int>>adj(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i];
		v[i]--;
		adj[i].pb(v[i]);
	}


	// for (int i = 0; i < n; i++) {
	// 	cout << i << " -> ";
	// 	for (auto &x : adj[i]) {
	// 		cout << x << " ";
	// 	}
	// 	cout << endl;
	// }
	vector<int>len(n, -1);

	vector<pair<int, int>> cycleNodes;

	for (int i = 0; i < n; i++) {
		if (len[i] == -1) {
			cycle = 0;
			cntNodes = 0;
			dfs(i, adj, len);
			cycleNodes.pb({cntNodes, cycle});
		}
	}

	// for (auto &x : cycleNodes) {
	// 	cout << x.first << " " << x.second << endl;
	// }
	sort(all(cycleNodes));
	int ans = 0;
	for (int i = 0; i < sz(cycleNodes) - 2; i++) {
		ans += cycleNodes[i].second * cycleNodes[i].second;
	}

	int mx = 0;
	if (sz(cycleNodes) > 1) {
		int curChoice1 = cycleNodes[sz(cycleNodes) - 1].first * cycleNodes[sz(cycleNodes) - 1].first + cycleNodes[sz(cycleNodes) - 2].first * cycleNodes[sz(cycleNodes) - 2].first;
		int curChoice2 = cycleNodes[sz(cycleNodes) - 1].second + cycleNodes[sz(cycleNodes) - 2].second;
		curChoice2 *= curChoice2;
		mx = max(curChoice2, curChoice1);
	} else if (sz(cycleNodes) == 1) {
		mx += (cycleNodes[0].second) * (cycleNodes[0].second);
	}
	ans += mx;
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