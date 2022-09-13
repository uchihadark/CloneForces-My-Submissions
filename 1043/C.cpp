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
    string s;
    cin >> s;
    int n = s.size();

    vi ans(n, 0);
    char mn = 'z';
    for (int i = 0; i < n; i++) {
        mn = min(mn, s[i]);
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == mn)cnt++;
    }
    bool f = 0;
    for (int i = 0; i < n; i++) {
        if (s[i] == mn) {
            int ind = i;
            while (ind < n && s[ind] == mn) {
                ind++;
                cnt--;
            }
            if (cnt == 0) {
                f = 0;
            } else {
                f = 1;
            }
            ind--;
            ans[ind] = 1;
            i = ind;
        } else {
            if (f == 0) {
                ans[i] = 0;
            } else {
                int ind = i;
                while (ind < n && s[ind] != mn) {
                    ind++;
                }
                ind--;
                ans[ind] = 1;
                i = ind;
            }
        }
    }

    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << endl;
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