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
	int n, a, b;
	cin >> n >> a >> b;

	int low = 1, high = inf;
	int ans = -1;
	while (low <= high) {
		int mid = (high + low) / 2;
		if (mid > (a + b)) {
			high = mid - 1;
			continue;
		}
		int groups = (a / mid) + (b / mid);
		if (groups >= n && mid <= a && mid <= b) {
			ans = max(ans, mid);
			low = mid + 1;
		} else {
			high = mid - 1;
		}
	}
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