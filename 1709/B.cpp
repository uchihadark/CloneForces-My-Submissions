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
    int m;
    cin >> m;
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vi val;
    for (int i = 1; i < n; i++) {
        if (v[i - 1] > v[i]) {
            val.pb(v[i - 1] - v[i]);
        } else {
            val.pb(0);
        }
    }
    vi pre(sz(val), 0);
    pre[0] = val[0];
    for (int i = 1; i < sz(val); i++) {
        pre[i] = pre[i - 1] + val[i];
    }
    vi val2;
    for (int i = n - 2; i >= 0; i--) {
        if (v[i + 1] > v[i]) {
            val2.pb(v[i + 1] - v[i]);
        } else {
            val2.pb(0);
        }
    }
    reverse(all(val2));
    vi suf(sz(val2), 0);

    suf[0] = val2[0];
    for (int i = 1; i < sz(val2); i++) {
        suf[i] = suf[i - 1] + val2[i];
    }
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        a -= 2, b -= 2;
        if (a > b) {
            swap(a, b);
            if (a < 0) {
                cout << suf[b] << endl;
                continue;
            }
            cout << suf[b] - suf[a] << endl;
            continue;
        }
        if (a < 0) {
            cout << pre[b] << endl;
            continue;
        }
        cout << pre[b] - pre[a] << endl;
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