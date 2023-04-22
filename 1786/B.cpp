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
    int n, w, h;
    cin >> n >> w >> h;
    vector<int> a(n);
    for(auto &x : a){
        cin >> x;
    }
    vector<int> b(n);
    for(auto &x : b){
        cin >> x;
    }
    vector<int> ca;
    ca.pb(w);
    for(int i= 1;i<n;i++){
        int diff = a[i]-a[i-1];
        ca.pb(ca.back()+diff);
    }
    int low = 0, high = 2*w;
    while(low <= high){
        int mid = (low+high)/2;
        int left = 0, right = 0;
        int prev = mid;
        for(int i= 0;i<n;i++){
            int stCake = ca[i]-w;
            int enCake = ca[i]+w;

            int diff  = 0;
            if(i > 0){
                diff = b[i]-b[i-1];
            }
            int stDis = prev + diff - h;
            int enDis = prev + diff + h;
            if(stDis < stCake)right++;
            else if(enDis > enCake)left++;
            prev = prev+diff;
        }
        if(left == 0 && right == 0){
            cout <<"YES\n";
            return;
        }
        if(left > 0){
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout <<"NO\n";
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