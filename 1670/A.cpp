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
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        if (v[i] < 0)cnt++;
    }
    if (cnt == 0) {
        for (int i = 1; i < n; i++) {
            if (v[i] < v[i - 1]) {
                cout << "NO\n";
                return;
            }
        }
        cout << "YES\n";
        return;
    }
    for (int i = 0; i < cnt; i++) {
        if (v[i] < 0)continue;
        else {
            v[i] = -1 * v[i];
        }
    }
    for (int i = cnt; i < n; i++) {
        v[i] = abs(v[i]);
    }
    for (int i = 1; i < n; i++) {
        if (v[i] < v[i - 1]) {
            cout << "NO\n";
            return;
        }
    }
    cout << "YES\n";

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