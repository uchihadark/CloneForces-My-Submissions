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
    sort(all(v));
    int ans = 0;
    map<int, bool>done;
    for (int i = n - 1; i >= 0; i--) {
        if (i == n - 1) {
            ans += v[i];
            done[v[i]] = true;
        } else {
            while (done[v[i]] == true && v[i] > 0) {
                v[i]--;
            }
            done[v[i]] = true;
            ans += v[i];
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