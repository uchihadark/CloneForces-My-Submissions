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

	vector<int>factors;
	int tmp = n;
	if (tmp % 2 == 0) {
		factors.pb(2);
		while (tmp % 2 == 0) {
			tmp /= 2;
		}
	}

	for (int i = 3; i * i <= tmp; i += 2) {
		if (tmp % i == 0) {
			factors.pb(i);
			while (tmp % i == 0) {
				tmp /= i;
			}
		}
	}
	if (tmp > 2) {
		factors.pb(tmp);
	}
	int ans = 1;
	for (auto &x : factors) {
		ans *= x;
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