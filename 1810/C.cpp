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
	int n, c, d;
	cin >> n >> c >> d;

	vector<int> v(n);
	map<int, int> cnt;
	for (int i = 0; i < n; i++) {
		cin >> v[i];
		cnt[v[i]]++;
	}
	vector<int> arr;
	for (auto &x : cnt) {
		arr.pb(x.first);
	}

	int ans = inf;
	for (int i = 0; i < sz(arr); i++) {
		int insert = arr[i] - (i + 1);
		int del = 0;
		del += n - (i + 1);
		int curCost = c * del + d * insert;
		ans = min(ans, curCost);
	}
	ans = min(ans, n * c + d);
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