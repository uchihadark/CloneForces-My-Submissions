#include <bits/stdc++.h>
int mod = 1e9 + 7;
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

int powermod(int a, int b){int ans = 1;while (b){if (b & 1) ans = (ans * a) % mod;b = b / 2;a = (a * a) % mod;}return ans;}


void Solve() {
    int n, m;
    cin >> n >>m;
    mod = m;
    int ans = powermod(3,n);
    ans--;
    if(ans < 0)ans += mod;
    cout << ans <<endl;

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