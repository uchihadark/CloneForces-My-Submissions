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
    int move = 0;
    bool pos = 1;
    while (1) {
        int ind = -1;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (v[i] == 0)cnt++;
        }
        if (cnt > 1) {
            pos = 0;
            break;
        }
        for (int i = 1; i < n; i++) {
            if (v[i] <= v[i - 1]) {
                ind = i - 1;
                break;
            }
        }
        if (ind == -1) {
            break;
        }
        while (v[ind] >= v[ind + 1]) {
            v[ind] /= 2;
            move++;
            if (v[ind] == 0) {
                break;
            }

        }

    }
    // for (auto &val : v) {
    //     cout << val << " ";
    // }
    // cout << endl;
    for (int i = 1; i < n; i++) {
        if (v[i] <= v[i - 1]) {
            pos = 0;
            break;
        }
    }
    if (pos) {
        cout << move << endl;
    } else {
        cout << -1 << endl;
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

