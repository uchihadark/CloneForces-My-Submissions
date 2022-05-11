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
    string tmp = s;
    int k;
    cin >> k;
    map<char, bool> cnt;
    for (int i = 0; i < k; i++) {
        char a;
        cin >> a;
        cnt[a] = true;
    }
    int in = -1;
    for (int i = 0; i < n; i++) {
        if (cnt.count(s[i]) == false) {
            in = i;
            break;
        }
    }
    int ans = 0;
    if (in == -1 && n > 1) {
        cout << 1 << endl;
        return;
    }
    int cn = 0;
    for (int i = 0; i < n; i++) {
        if (cnt.count(s[i]) == true) {
            cn++;
        } else {
            break;
        }
    }
    if (cn > 1) {
        ans = 1;
    }
    vi last;
    for (int i = 0; i < n; i++) {
        if (cnt.count(s[i])) {
            int ind = i;
            while (ind < n && s[ind] == s[i]) {
                ind++;
            }
            ind--;
            if (last.empty() == true) {
                last.pb(ind);
                ans = max(ans, i);
            } else {
                int l = last.back();
                int diff = i - l;
                ans  = max(ans, diff);
                last.pb(ind);
            }
            i =  ind;
        } else {
            continue;
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