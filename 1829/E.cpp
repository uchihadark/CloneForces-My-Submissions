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

int sum = 0;

void dfs(int i, int j, int n, int m, vector<vector<int>>&v, vector<vector<int>>&vis
        ) {
	sum += v[i][j];
	vis[i][j] = 1;

	// cout << v[i][j] << " ";

	int x[] = {1, 0, 0, -1};
	int y[] = {0, 1, -1, 0};

	for (int k = 0; k < 4; k++) {
		int dx = i + x[k];
		int dy = j + y[k];
		if (dx >= 0 && dx < n && dy >= 0 && dy < m && vis[dx][dy] == 0 && v[dx][dy] != 0) {
			dfs(dx, dy, n, m, v, vis);
		}
	}
}


void Solve() {
	int n, m;
	cin >> n >> m;
	vector<vector<int>>v(n, vector<int>(m));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> v[i][j];
		}
	}
	int ans = 0;
	vector<vector<int>>vis(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (v[i][j] != 0 && vis[i][j] == 0) {
				sum = 0;
				dfs(i, j, n, m, v, vis);
				ans = max(ans, sum);
				// cout << endl;
			}
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