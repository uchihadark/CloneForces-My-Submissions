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
    vi pre1;
    int ans = 0;
    for (int i = 1; i < n; i += 2) {
        if (i - 1 >= 0 && i + 1 < n) {
            int diff1 = v[i] - v[i - 1];
            int diff2 = v[i] - v[i + 1];
            int mx = -1;
            if (diff1 <= 0) {
                mx = max(mx, abs(diff1));
            }
            if (diff2 <= 0) {
                mx = max(mx, abs(diff2));
            }
            mx++;
            ans += mx;
            if (pre1.empty() == true) {
                pre1.pb(mx);
            } else {
                int num = pre1.back();
                num += mx;
                pre1.pb(num);
            }
        }
    }
    if (n & 1) {
        cout << ans << endl;
        return;
    }
    vi vv;
    for (int i = 2; i < n; i += 2) {
        if (i - 1 >= 0 && i + 1 < n) {
            int diff1 = v[i] - v[i - 1];
            int diff2 = v[i] - v[i + 1];
            int mx = -1;
            if (diff1 <= 0) {
                mx = max(mx, abs(diff1));
            }
            if (diff2 <= 0) {
                mx = max(mx, abs(diff2));
            }
            mx++;
            vv.pb(mx);
        }

    }
    vi suf2(sz(vv), 0);
    suf2[sz(vv) - 1] = vv[sz(vv) - 1];
    for (int i = sz(vv) - 2; i >= 0; i--) {
        suf2[i] = suf2[i + 1] + vv[i];
    }
    ans = min(ans, suf2[0]);
    for (int i = 0; i < sz(suf2) - 1; i++) {
        int num = pre1[i] + suf2[i + 1];
        ans = min(ans, num);
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