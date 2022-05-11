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

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void Solve() {
    int n, k;
    cin >> n >> k;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }

    map<int, int> cnt;
    for (int i = 30; i >= 0; i--) {
        int cntt = 0;
        for (int j = 0; j < n; j++) {
            if (v[j] & (1 << i)) {
                continue;
            } else {
                cntt++;
            }
        }
        cnt[i] = cntt;
    }
    int ans = 0;
    for (int i = 30; i >= 0; i--) {
        if (cnt[i] == 0) {
            ans += (1 << i);
        } else if (cnt[i] <= k) {
            ans += (1 << i);
            k -= cnt[i];
        }
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