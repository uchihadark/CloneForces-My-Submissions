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
    string pos;
    for (char i = 'a'; i <= 'z' && k > 0; i++, k--) {
        pos.pb(i);
    }
    string ans;
    while (ans.size() != n) {
        for (int i = 0; i < sz(pos); i++) {
            if (sz(ans) == n) {
                break;
            }
            for (int j = i; j < sz(pos); j++) {
                if (j == i) {
                    ans.pb(pos[i]);
                    continue;
                }
                if (sz(ans) == n) {
                    break;
                }
                ans.pb(pos[i]);
                if (sz(ans) == n) {
                    break;
                }
                ans.pb(pos[j]);
            }
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