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
    int n, k, b, s;
    cin >> n >> k >> b >> s;

    int req = k * b;

    if (req > s) {
        cout << -1 << endl;
        return;
    }
    int left = s - req;
    vi ans(n, 0);
    ans[0] = req;
    ans[0] += min(k - 1LL, left);
    left -= min(k - 1LL, left);
    int i = 1;
    while (left > 0 && i < n) {
        ans[i++] = min(k - 1, left);
        left -= min(k - 1, left);
    }
    if (left != 0) {
        cout << -1 << endl;
        return;
    }
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << endl;
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