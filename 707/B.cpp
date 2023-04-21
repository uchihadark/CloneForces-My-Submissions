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
    int n, m,k;
    cin >>n >> m >>k;
    vector<vector<pair<int,int>>>adj(n);
    for(int i= 0;i<m;i++){
        int u, v,l;
        cin >> u >> v >> l;
        u--,v--;
        adj[u].pb({v,l});
        adj[v].pb({u,l});
    }
    int ans = inf;
    map<int,int> storages;
    for(int i= 0;i<k;i++){
        int cur;
        cin >> cur;
        cur--;
        storages[cur] = 1;
    }
    for(auto &x : storages){
        int par = x.first;
        for(auto &x : adj[par]){
            if(storages.count(x.first) == false){
                ans = min(ans,x.second);
            }
        }
    }
    if(ans == inf)ans = -1;
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