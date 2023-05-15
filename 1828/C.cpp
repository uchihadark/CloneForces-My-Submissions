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
	int n;
	cin >> n;
	vi a(n), b(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	map<int, int> cnt;
	sort(all(a));
	for (int i = 0; i < n; i++) {
		int cur = b[i];
		if (cnt.count(b[i]))continue;

		int bigger = 0;
		auto it = upper_bound(all(a), cur);
		if (it == a.end()) {
			cout << 0 << endl;
			return;
		}
		int ind = it - a.begin();
		int curCnt = n - ind;
		cnt[cur] = curCnt;
	}
	// for (auto &x : cnt) {
	// 	cout << x.first << " " << x.second << endl;
	// }
	sort(all(b));
	int ans = 1;
	int done = 0;
	for (int i = n - 1; i >= 0; i--) {
		int totalWays = cnt[b[i]] - done;
		totalWays %= mod;
		ans %= mod;
		ans *= (totalWays) % mod;
		ans %= mod;
		done++;
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