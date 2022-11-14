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
// #define inf      1e18
#define endl    "\n"
using namespace std;

const int inf = 1LL << 62;

int fun(int x, int y, int z) {
    int ans = (x - y) * (x - y) + (y - z) * (y - z) + (z - x) * (z - x);
    return ans;
}

void Solve() {
    int x, y, z;
    cin >> x >> y >> z;
    vi a(x), b(y), c(z);
    for (auto &x : a) {
        cin >> x;
    }
    for (auto &x : b) {
        cin >> x;
    }
    for (auto &x : c) {
        cin >> x;
    }
    sort(all(a));
    sort(all(b));
    sort(all(c));
    int ans = inf;

    for (auto &x : a) {
        auto it = lower_bound(all(b), x);
        vi v1;
        int ind = it - b.begin();
        if (ind >= 0 && ind < b.size()) {
            v1.pb(b[ind]);
        }
        if (ind - 1 >= 0) {
            v1.pb(b[ind - 1]);
        }
        if (ind + 1 < b.size()) {
            v1.pb(b[ind + 1]);
        }

        it = lower_bound(all(c), x);
        ind = it - c.begin();
        vi v2;
        if (ind >= 0 && ind < c.size()) {
            v2.pb(c[ind]);
        }
        if (ind - 1 >= 0) {
            v2.pb(c[ind - 1]);
        }
        if (ind + 1 < c.size()) {
            v2.pb(c[ind + 1]);
        }

        for (int i = 0; i < v1.size(); i++) {
            for (int j = 0; j < v2.size(); j++) {
                ans = min(ans, fun(x, v1[i], v2[j]));
            }
        }

    }

    for (auto &x : b) {
        auto it = lower_bound(all(a), x);
        vi v1;
        int ind = it - a.begin();
        if (ind >= 0 && ind < a.size()) {
            v1.pb(a[ind]);
        }
        if (ind - 1 >= 0) {
            v1.pb(a[ind - 1]);
        }
        if (ind + 1 < a.size()) {
            v1.pb(a[ind + 1]);
        }

        it = lower_bound(all(c), x);
        ind = it - c.begin();
        vi v2;
        if (ind >= 0 && ind < c.size()) {
            v2.pb(c[ind]);
        }
        if (ind - 1 >= 0) {
            v2.pb(c[ind - 1]);
        }
        if (ind + 1 < c.size()) {
            v2.pb(c[ind + 1]);
        }

        for (int i = 0; i < v1.size(); i++) {
            for (int j = 0; j < v2.size(); j++) {
                ans = min(ans, fun(v1[i], x, v2[j]));
            }
        }
    }

    for (auto &x : c) {
        auto it = lower_bound(all(b), x);
        vi v1;
        int ind = it - b.begin();
        if (ind >= 0 && ind < b.size()) {
            v1.pb(b[ind]);
        }
        if (ind - 1 >= 0) {
            v1.pb(b[ind - 1]);
        }
        if (ind + 1 < b.size()) {
            v1.pb(b[ind + 1]);
        }

        it = lower_bound(all(a), x);
        ind = it - a.begin();
        vi v2;
        if (ind >= 0 && ind < a.size()) {
            v2.pb(a[ind]);
        }
        if (ind - 1 >= 0) {
            v2.pb(a[ind - 1]);
        }
        if (ind + 1 < a.size()) {
            v2.pb(a[ind + 1]);
        }

        for (int i = 0; i < v1.size(); i++) {
            for (int j = 0; j < v2.size(); j++) {
                ans = min(ans, fun(v2[j], v1[i], x));
            }
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