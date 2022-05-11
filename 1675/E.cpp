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
    int n, k;
    cin >> n >> k;
    string s;
    cin >> s;
    vector<pair<char, char>> done;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'a')continue;
        if (done.empty()) {
            int cur = s[i] - 'a';
            int mn = min(cur, k);
            k -= mn;
            char tmp = s[i] - mn;
            done.pb({s[i], tmp});
            s[i] = tmp;
        } else {

            sort(all(done));
            // for (auto &val : done) {
            //     cout << val.first << " " << val.second << endl;
            // }
            bool found = 0;
            for (auto &val : done) {
                int f = val.first;
                int ss = val.second;
                if (s[i] <= f && s[i] >= ss) {
                    s[i] = ss;
                    found = 1;
                    break;
                }
            }
            if (found == 0) {
                pair<char, char> last = done.back();
                if (last.first > s[i] && k == 0) {
                    continue;
                }
                int cur = s[i] - last.first;
                int mn = min(cur, k);
                k -= mn;
                char tmp = s[i] - mn;
                bool chk = 0;
                if (tmp == last.first) {
                    done.pb({s[i], last.second});
                    s[i] = last.second;
                    chk = 1;
                }
                if (chk)continue;
                else {
                    done.pb({s[i], tmp});
                    s[i] = tmp;
                }

            }
        }
    }
    cout << s << endl;
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