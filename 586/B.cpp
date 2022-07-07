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
    vi v1(n - 1), v2(n - 1);
    for (int i = 0; i < n - 1; i++) {
        cin >> v1[i];
    }
    for (int i = 0; i < n - 1; i++) {
        cin >> v2[i];
    }
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vi going(n, 0);
    for (int i = 0; i < n; i++) {
        int cur = 0;
        int ind = n - 1 - i;
        cur += v[n - 1 - i];
        for (int j = ind ; j < n - 1; j++) {
            cur += v2[j];
        }
        for (int j = ind - 1; j >= 0; j--) {
            cur += v1[j];
        }
        going[n - 1 - i] = cur;
    }
    vi coming(n, 0);
    for (int i = 0; i < n; i++) {
        int cur = 0;
        cur += v[i];
        int ind = i - 1;
        for (int j = 0 ; j <= min(ind, n - 2); j++) {
            cur += v1[j];
        }
        for (int j = ind + 1; j < n - 1; j++) {
            cur += v2[j];
        }
        coming[i] = cur;
    }
    int ans = inf;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != j) {
                ans = min(ans, coming[i] + going[j]);
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