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
    int n, k;
    cin >> n >> k;

    int mn = (n - k);
    if (k == 0) {
        cout << 0 << " " << 0 << endl;
        return;
    }
    if (mn > 0) {
        mn = 1;
    }

    int mx = 0;
    if (n % 3 == 0) {
        int total = n / 3;
        if (total >= k) {
            mx += (3 * k) - k;
        } else {
            mx += (total * 3) - total;
            k -= total;
            mx = max(0LL, mx - k);
        }
        cout << mn << " " << mx << endl;
    } else {
        int rem = n % 3;
        n -= rem;
        int total = n / 3;
        if (total >= k) {
            mx += (3 * k) - k;
        } else {
            mx += (total * 3) - total;
            mx++;
            k -= (rem - 1);
            k -= total;
            mx = max(0LL, mx - k);
        }
        cout << mn << " " << mx << endl;
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