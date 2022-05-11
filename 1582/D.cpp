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
    if (n % 2 == 0) {
        vi ans(n, 0);
        for (int i = 0; i < n; i += 2) {
            ans[i] = v[i + 1];
            ans[i + 1] = (-1 * v[i]);
        }
        for (auto &val : ans) {
            cout << val << " ";
        }
        cout << endl;
    } else {
        // x, y, z
        // x*(-z) + y*(-z) + z(x+y) => -xz - yz + xz + yz = 0
        // in set of 3 non-zero numbers there always two number whose sum is not 0
        vi f;
        for (int i = 0; i < n - 3; i++) {
            f.pb(v[i]);
        }

        for (int i = 0; i < sz(f); i += 2) {
            f[i] = v[i + 1];
            f[i + 1] = (-1 * v[i]);
        }
        vi left;
        int x = v[n - 3];
        int y = v[n - 2];
        int z = v[n - 1];
        left.pb(x);
        left.pb(y);
        left.pb(z);
        if (left[0] + left[1] != 0) {
            x = left[0];
            y = left[1];
            z = left[2];
        } else if (left[0] + left[2] != 0) {
            z = left[0];
            y = left[2];
            z = left[1];
        } else if (left[1] + left[2] != 0) {
            x = left[1];
            y = left[2];
            z = left[0];
        }

        for (int i = n - 3; i < n; i++) {
            if (v[i] == z) {
                f.pb((x + y));
                break;
            } else {
                f.pb(-1 * (z));
            }
        }
        while (sz(f) != n) {
            f.pb(-1 * (z));
        }

        for (auto &val : f) {
            cout << val << " ";
        }
        cout << endl;



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