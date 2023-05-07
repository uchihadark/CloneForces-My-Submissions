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
	vi a, b;
	int ans = inf;
	for (int i = 0; i < n; i++) {
		int t;
		cin >> t;
		string s;
		cin >> s;
		if (s[0] == '1') {
			a.pb(t);
		}
		if (s[1] == '1') {
			b.pb(t);
		}
		if (s[0] == '1' && s[1] == '1') {
			ans = min(ans, t);
		}
	}

	if (sz(a) == 0 || sz(b) == 0) {
		cout << -1 << endl;
		return;
	}
	sort(all(a));
	sort(all(b));
	cout << min(a[0] + b[0], ans) << endl;
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