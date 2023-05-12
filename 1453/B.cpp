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
	vi v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	int sum = 0;
	for (int i = 1; i < n; i++) {
		int d = abs(v[i] - v[i - 1]);
		sum += d;
	}

	int ans = inf;
	for (int i = 0; i < n; i++) {
		int x = i;
		int diff1 = 0, diff2 = 0;
		if (x - 1 >= 0) {
			diff1 = abs(v[x] - v[x - 1]);
		}
		if (x + 1 < n) {
			diff2 = abs(v[x + 1] - v[x]);
		}
		int cur = sum - diff1 - diff2;
		if (x + 1 < n && x - 1 >= 0) {
			cur += abs(v[x - 1] - v[x + 1]);
		}
		ans = min(ans, cur);
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