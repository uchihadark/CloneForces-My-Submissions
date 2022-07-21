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

    // example abcd
    // we can get cbabcd, if we somehow get d in staring it would work,
    // so lets do this, abcdc
    // then, dcbabcdc
    // finallay, we do cdcbabcdc

    int st = 0, en = sz(s) - 1;
    bool f = 0;
    while (st <= en) {
        if (s[st++] != s[en--]) {
            f = 1;
            break;
        }
    }
    if (f == 0) {
        cout << 0 << endl;
        return;
    }
    cout << 3 << endl;
    cout << "R " << sz(s) - 1 << endl;
    cout << "L " << sz(s) << endl;
    cout << "L " << 2 << endl;
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