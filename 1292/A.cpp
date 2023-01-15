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
    int n, q;
    cin >> n >> q;
    map<pair<int, int>, bool> check;
    int closed = 0;
    for (int i = 0; i < q; i++) {
        int x, y;
        cin >> x >> y;
        if (x == 1) {
            if (check[ {x, y}] == true) {
                check[ {x, y}] = false;
                if (check[ {2, y}])closed--;
                if (y - 1 >= 1) {
                    if (check[ {2, y - 1}])closed--;
                }
                if (y + 1 <= n) {
                    if (check[ {2, y + 1}])closed--;
                }
            } else {
                check[ {x, y}] = true;
                if (check[ {2, y}])closed++;
                if (y - 1 >= 1) {
                    if (check[ {2, y - 1}])closed++;
                }
                if (y + 1 <= n) {
                    if (check[ {2, y + 1}])closed++;
                }
            }
        } else {
            if (check[ {x, y}] == true) {
                check[ {x, y}] = false;
                if (check[ {1, y}])closed--;
                if (y - 1 >= 1) {
                    if (check[ {1, y - 1}])closed--;
                }
                if (y + 1 <= n) {
                    if (check[ {1, y + 1}])closed--;
                }
            } else {
                check[ {x, y}] = true;
                if (check[ {1, y}])closed++;
                if (y - 1 >= 1) {
                    if (check[ {1, y - 1}])closed++;
                }
                if (y + 1 <= n) {
                    if (check[ {1, y + 1}])closed++;
                }
            }
        }
        if (closed > 0) {
            cout << "NO\n";
        } else {
            cout << "YES\n";
        }
    }
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