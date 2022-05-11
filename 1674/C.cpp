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

int binpow(int a, int b) {
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

void Solve() {
    //didn't read the problem properly during the contest fml
    string s, t;
    cin >> s >> t;
    if (sz(t) > 1 ) {
        for (int i = 0; i < sz(t); i++) {
            if (t[i] == 'a') {
                cout << -1 << endl;
                return;
            }
        }
    } else {
        if (t[0] == 'a') {
            cout << 1 << endl;
            return;
        }
    }
    int n = sz(s);
    cout << binpow(2, n) << endl;

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