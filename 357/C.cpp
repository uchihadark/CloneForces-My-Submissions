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

	set<int> s;
	for (int i = 1; i <= n; i++) {
		s.insert(i);
	}
	map<int, int> ans;
	for (int i =  0; i < m; i++) {
		int l, r, x;
		cin >> l >> r >> x;
		vector<int> er;
		auto it = s.lower_bound(l);
		while (it != s.end()) {
			if (*it > r)break;
			if (*it != x) {
				er.pb(*it);
				ans[*it] = x;
			}
			it++;
		}
		for (auto &x : er) {
			s.erase(x);
		}
	}
	for (int i = 1; i <= n; i++) {
		cout << ans[i] << " ";
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