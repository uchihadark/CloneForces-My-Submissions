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
    for(auto &x : v){
        cin >> x;
    }
    int ans = 0;
    vector<int> dp(n,0);
    for(int i= n-1;i>=0;i--){
        int cnt = 0;
        for(int j = i-1;j>=0;j--){
            if(v[i] > v[j]){ // a c pair
                ans += cnt;
            }
            cnt += dp[j];
            if(v[j] > v[i]){ // b d pair
                dp[j]++;
            }
        }
    }
    cout << ans <<endl;
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