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
    int f = -1, s = -1, t = -1;
    int cnt = 0;
    for (int i = n - 1; i >= 0; i--) {
        if (cnt >= 2) {
            int cur = v[i];
            if (cnt % 2 == 0) {
                if (cur > f || cur > s) {
                    cout << "NO\n";
                    return;
                } else {
                    t = s;
                    s = cur;
                    cnt++;
                    continue;
                }
            } else {
                if (cur > f) {
                    cout << "NO\n";
                    return;
                } else {
                    if (cur > s) {
                        f = s;
                        s = cur;
                    } else {
                        f = cur;
                    }
                    cnt++;
                    continue;
                }
            }

        } else {
            if (f == -1) {
                f = v[i];
                cnt++;
                continue;
            }
            if (s == -1) {
                s = v[i];
                cnt++;
                if (f > s) {
                    swap(f, s);
                }
                continue;
            }
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