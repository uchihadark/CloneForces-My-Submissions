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
    int n;
    cin >>n;
    if(n&1){
        cout << 1 <<endl;
        return;
    }
    int ans = -1;
    for(int i = 1;i<=15;i++){
        int zero = i-1;
        int ind = i-1;
        int total = 2*i-1;
        int cur  = 0;
        for(int j = ind;j<total;j++){
            cur += binpow(2,j);
            if(cur > n)break;
        }
        if(cur > n)break;
        if(n%cur == 0){
            ans = max(ans,cur);
        }
    }
    cout <<ans <<endl;
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