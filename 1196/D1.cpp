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

int fun(string s, int ind) {
    string s1 = "RGB";
    string s2 = "GBR";
    string s3 = "BRG";

    int cnt = 0;
    int c1 = 0, c2 = 0, c3 = 0;
    for (int i = ind; i < sz(s); i++) {
        if (cnt == 3) {
            cnt = 0;
        }
        if (s[i] != s1[cnt]) {
            c1++;
        }

        if (s[i] != s2[cnt]) {
            c2++;
        }

        if (s[i] != s3[cnt]) {
            c3++;
        }
        cnt++;
    }
    return min(c1, min(c2, c3));

}

void Solve() {
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    string sub;
    for (int i = 0; i < k; i++) {
        sub.pb(s[i]);
    }
    int ans = inf;
    int ind = 0;
    int cur = fun(sub, ind);
    if (cur == 0) {
        cout << 0 << endl;
        return;
    } else {
        ans = min(ans, cur);
    }
    ind++;
    for (int i = k; i < n; i++) {
        sub.pb(s[i]);
        cur = fun(sub, ind);
        if (cur == 0) {
            cout << 0 << endl;
            return;
        } else {
            ans = min(ans, cur);
        }
        ind++;
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