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
    int cur = 1;
    vi st;
    int ans = 0;
    vector<pair<string, int>> cmd(2 * n);
    for (int i = 0; i < 2 * n; i++) {
        cin >> cmd[i].first;
        if (cmd[i].first == "add") {
            cin >> cmd[i].second;
        }
    }

    for (int i = 0; i < 2 * n; i++) {
        if (cmd[i].first == "add") {
            st.pb(cmd[i].second);
        } else {
            if (st.empty() == true) {

            } else {
                if (st.back() == cur) {
                    st.pop_back();
                } else {
                    ans++;
                    st.clear();
                }
            }
            cur++;

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