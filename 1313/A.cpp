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
    vi v(3);
    for (int i = 0; i < 3; i++) {
        cin >> v[i];
    }
    sort(all(v));
    int ans = 0;

    if (v[0] > 0) {
        ans++;
        v[0]--;
    }
    if (v[1] > 0) {
        ans++;
        v[1]--;
    }
    if (v[2] > 0) {
        ans++;
        v[2]--;
    }
    if (v[0] > 0 && v[2] > 0) {
        ans++;
        v[0]--, v[2]--;
    }
    if (v[1] > 0 && v[2] > 0) {
        ans++;
        v[1]--, v[2]--;
    }
    if (v[0] > 0 && v[1] > 0) {
        ans++;
        v[0]--, v[1]--;
    }
    if (v[0] > 0 && v[1] > 0 && v[2] > 0) {
        ans++;
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