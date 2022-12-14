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
    string s;
    cin >> s;
    map<string, vector<pair<int, int>>> cnt;
    for (int i = 0; i < n - 1; i++) {
        string tmp = "";
        tmp.pb(s[i]);
        tmp.pb(s[i + 1]);
        cnt[tmp].pb({i, i + 1});
    }
    bool f = 0;
    for (auto &x : cnt) {
        if (f) {
            break;
        }
        vector<pair<int, int>> &tmp = x.second;
        if (sz(tmp) > 1) {
            if (tmp[0].second != tmp[sz(tmp) - 1].first) {
                f = 1;
                break;
            }
        }
    }
    if (f) {
        cout << "YES\n";
    } else {
        cout << "NO\n";
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