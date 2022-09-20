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

int cnt = 0;

void fun(int mn, int mx, vi &v, map<int, bool>&chk) {
    if (sz(v) == 0) {
        return;
    }
    if (sz(v) == 1) {
        chk[v[0]] = 1;
        return;
    }
    int mid = mn + mx;
    mid /= 2;
    vi lft, rght;
    int mn1 = inf, mx1 = -inf;
    int mn2 = inf, mx2 = -inf;
    int sum1 = 0, sum2 = 0;
    for (auto &x : v) {
        if (x <= mid) {
            lft.pb(x);
            mn1 = min(mn1, x);
            mx1 = max(mx1, x);
            sum1 += x;
        } else {
            rght.pb(x);
            mx2 = max(mx2, x);
            mn2 = min(mn2, x);
            sum2 += x;
        }
    }
    // for (auto &x : lft) {
    //     cout << x << " ";
    // }
    // cout << endl;

    // for (auto &x : rght) {
    //     cout << x << " ";
    // }
    // cout << endl;
    // cout << endl;
    chk[sum1] = true;
    chk[sum2] = true;
    if (lft == v || rght == v) {
        return;
    }

    fun(mn1, mx1, lft, chk);
    fun(mn2, mx2, rght, chk);
}

void Solve() {
    int n, q;
    cin >> n >> q;
    vi v(n);
    int mn = inf, mx = -inf;
    map<int, bool> chk;

    for (auto &x : v) {
        cin >> x;
        mn = min(mn, x);
        mx = max(mx, x);
    }
    int sum = accumulate(all(v), 0LL);
    chk[sum] = 1;
    fun(mn, mx, v, chk);
    for (int i = 0; i < q; i++) {
        int num;
        cin >> num;
        if (chk[num]) {
            cout << "Yes\n";
        } else {
            cout << "No\n";
        }
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