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
    vector<int> v(n);
    for(auto &x : v){
        cin >> x;
    }
    vi prefix(n);
    prefix[0] = v[0];
    for(int i= 1;i<n;i++){
        prefix[i] += prefix[i-1]+v[i];
    }

    for(int i= 0;i<q;i++){
        int l,r,k;
        cin >> l >> r >>k;
        l--,r--;
        int sum1 = 0;
        if(l-1 >= 0){
            sum1 = prefix[l-1];
        }
        // cout <<l <<" "<< r <<endl;
        int sum2 = prefix[n-1]-prefix[r];
        int sum3 = k*(r-l+1);
        int total = sum3+sum1+sum2;
        // cout << sum1 <<" "<< sum2 <<" "<< sum3 <<endl;
        if(total&1){
            cout <<"YES\n";
        }else{
            cout <<"NO\n";
        }
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