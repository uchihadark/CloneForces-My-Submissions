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


void Solve(){
    int n;
    cin>>n;
    vector<int>adj[n+1];
    vector<int>v(n-1);
    for(int i = 0;i<n-1;i++){
        cin>>v[i];
        adj[v[i]].push_back(i+2);
    }
    // for(int i=1;i<=n;i++){
    //     if(sz(adj[i])){
    //         cout << i <<" : ";
    //         for(auto &x : adj[i]){
    //             cout<<x<<" ";
    //         }
    //         cout << endl;
    //     }
    // }
    queue<int>q;
    q.push(1);
    int ans = 1;
    while(q.empty() ==false){
        queue<int> tmp;
        while(q.empty() ==false){
            int cur = q.front();
            q.pop();
            for(auto &x : adj[cur]){
                // cout << x <<" ";
                tmp.push(x);
            }
        }
        ans += (sz(tmp)%2);
        q = tmp;
        // cout <<endl;
    }
    cout << ans<< endl;
    
    
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