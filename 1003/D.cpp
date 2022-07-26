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
    int n, q;
    cin >> n >> q;
    map<int, int> s;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        s[a]++;
    }

    for (int i = 0; i < q; i++) {
        int a;
        cin >> a;
        int ans = 0;
        for (int j = 30; j >= 0 && a > 0; j--) {
            int num = 1 << j;
            int req = min(a >> j, s[num]);
            ans += req;
            a -= (req * num);
        }
        if (a > 0) {
            cout << -1 << endl;
        } else {
            cout << ans << endl;
        }
    }
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