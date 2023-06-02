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
	int a, b, n , m ;
	cin >> a >> b >> n >> m;
	if (m > n) {
		cout << min(n * a, n * b) << endl;
		return;
	}
	int costDiscount = m * a;
	int woDiscount = (m + 1) * b;
	if (woDiscount <= costDiscount) {
		cout << b*n << endl;
	} else {
		int curNum = m + 1;
		int curCost = m * a;
		int div = n / (m + 1);
		int cost = div * curCost;
		int res = n - (m + 1) * div;
		cost += min(res * a, res * b);
		cout << cost << endl;
	}
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