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
	vector<vector<int>>dp(n, vector<int>(m, 0));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a;
			cin >> a;
			if (j == 0) {
				if (i - 1 >= 0) {
					dp[i][j] = a + dp[i - 1][j];
				} else {
					dp[i][j] = a;
				}
				continue;
			}
			if (i - 1 >= 0) {
				dp[i][j] = max(dp[i][j], dp[i - 1][j]);
			}
			dp[i][j] = max(dp[i][j], dp[i][j - 1]);
			dp[i][j] += a;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << dp[i][m - 1] << " ";
	}
	cout << endl;
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