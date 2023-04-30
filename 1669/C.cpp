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
	for (auto &x : v) {
		cin >> x;
	}
	vi odd, even;
	for (int i = 0; i < n; i++) {
		if (v[i] % 2) {
			odd.pb(i);
		} else {
			even.pb(i);
		}
	}
	if (sz(odd) == 0 || sz(even) == 0) {
		cout << "YES\n";
		return;
	}
	if (sz(odd) == sz(even) || abs(sz(odd) - sz(even)) == 1) {
		for (int i = 1; i < sz(odd); i++) {
			if (odd[i] - odd[i - 1] != 2) {
				cout << "NO\n";
				return;
			}
		}
		for (int i = 1; i < sz(even); i++) {
			if (even[i] - even[i - 1] != 2) {
				cout << "NO\n";
				return;
			}
		}
		cout << "YES\n";
		return;
	}
	cout << "NO\n";

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