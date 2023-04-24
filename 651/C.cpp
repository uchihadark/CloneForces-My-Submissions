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
    map<int,int>x,y;
    map<pi,int> cnt;
    for(int i= 0;i<n;i++){
        int xx,yy;
        cin >> xx >> yy ;
        cnt[{xx,yy}]++;
        x[xx]++;
        y[yy]++;
    }
    int ans = 0;
    for(auto &k : x){
        int num = k.second;
        ans += (num*(num-1))/2;
    }
    for(auto &k : y){
        int num = k.second;
        ans += (num*(num-1))/2;
    }
    for(auto &x : cnt){
        ans -= (x.second-1)*x.second/2;
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