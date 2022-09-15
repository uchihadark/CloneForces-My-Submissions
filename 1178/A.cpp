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
    int sum = 0;
    for(int i= 0;i<n;i++){
        cin >> v[i];
        sum += v[i];
    }
    int req = sum/2 + 1;
    int alice = v[0];
    req -= alice;
    vector<int> ans;
    ans.pb(1);
    for(int i= 1;i<n;i++){
        if(req > 0){
            if(v[i]*2 <= alice){
                req -= v[i];
                ans.pb(i+1);
            }
        }
    }
    if(req > 0){
        cout << 0 << endl;
    }else{
        cout << sz(ans)<< endl;
        for(auto &x : ans){
            cout << x <<" ";
        }
        cout <<endl;
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