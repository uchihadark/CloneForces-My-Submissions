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
    cin >> n;;
    vi a(n), b(n), c(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> c[i];
    }
    set<int> done;
    vi ans(n, 0);
    for (int  i = 0; i < n; i++) {
        if (c[i] != 0) {
            ans[i] = 1;
            done.insert(c[i]);
        }
    }
    while (1) {
        bool f = 0;
        for (int i = 0; i < n; ++i) {
            if (ans[i] == 0) {
                if (done.count(a[i]) == true || done.count(b[i])) {
                    if (done.count(a[i])) {
                        ans[i] = 1;
                        done.insert(b[i]);
                    } else {
                        ans[i] = 1;
                        done.insert(a[i]);
                    }
                    f = 1;
                }
            }

        }
        if (f == 0) {
            break;
        }
    }
    map<pair<int, int>, int>inv;
    for (int i = 0; i < n; i++) {
        inv[ {a[i], b[i]}] = i;
    }
    for (int i = 0; i < n; i++) {
        if (ans[i] == 0) {
            if (inv.count({b[i], a[i]})) {
                ans[i] = 2;
                ans[inv[ {b[i], a[i]}]] = 1;
            }
        }
    }
    map<int, int> aa, bb;
    for (int i = 0; i < n; i++) {
        aa[a[i]] = i;
        bb[b[i]] = i;
    }
    while (1) {
        bool found = 1;
        for (int i = 0; i < n; i++) {
            if (ans[i] == 0) {
                found = 0;
                break;
            }
        }
        if (found) {
            break;
        }
        vi ind;
        int req = -1;
        for (int i = 0; i < n; i++) {
            if (ans[i] == 0) {
                req = a[i];
                ind.pb(i);
                break;
            }
        }
        while (1) {
            int ii = ind.back();
            int num = b[ii];
            int i2 = aa[num];
            ind.pb(i2);
            if (b[i2] == req) {
                break;
            }
        }
        for (auto &val : ind) {
            ans[val] = 1;
        }
        ans[ind[0]] = 2;
    }
    int fi = 1LL;
    for (int  i = 0; i < n; i++) {
        fi %= mod;
        fi *= (ans[i] % mod);
        fi %= mod;
    }
    cout << fi << endl;

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