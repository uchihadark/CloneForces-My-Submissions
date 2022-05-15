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

int n , k;

int fun(string s) {
    string s1 = "RGB";
    string s2 = "GBR";
    string s3 = "BRG";

    int cnt = 0;
    int c1 = 0, c2 = 0, c3 = 0;
    int ans = inf;
    vi cnt1(n, 0), cnt2(n, 0), cnt3(n, 0);
    for (int i = 0; i < sz(s); i++) {
        if (cnt == 3) {
            cnt = 0;
        }
        if (s[i] != s1[cnt]) {
            c1++;
            cnt1[i] = 1;
        }
        if (s[i] != s2[cnt]) {
            c2++;
            cnt2[i] = 1;

        }
        if (s[i] != s3[cnt]) {
            c3++;
            cnt3[i] = 1;
        }
        if (i >= k) {
            c1 -= cnt1[i - k];
            c2 -= cnt2[i - k];
            c3 -= cnt3[i - k];
        }
        if (i >= k - 1) {
            ans = min(ans, c1);
            ans = min(ans, c2);
            ans = min(ans, c3);
        }
        cnt++;
    }
    return ans;

}

void Solve() {
    cin >> n >> k;
    string s;
    cin >> s;
    string sub;
    for (int i = 0; i < k; i++) {
        sub.pb(s[i]);
    }
    int ans = inf;
    cout << fun(s) << endl;


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