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

	vi v(n * m);
	for (int i = 0; i < n * m; i++) {
		cin >> v[i];
	}
	sort(all(v));
	int mx = v[sz(v) - 1];
	int mn = v[0];
	int ans = 0;
	if (n > m)swap(n, m);
	ans += (mx - v[0]) * (m - 1);
	ans += (mx - v[1]) * (n - 1);
	ans += ((n * m) - (n + m - 1)) * (mx - v[0]);

	int ans2 = 0;
	ans2 += (v[n * m - 1] - mn) * (m - 1);
	ans2 += (v[n * m - 2] - mn) * (n - 1);
	ans2 += ((n * m) - (n + m - 1)) * (v[n * m - 1] - mn);
	cout << max(ans, ans2) << endl;

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