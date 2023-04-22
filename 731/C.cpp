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

int cnt = 0;
int mx = 0;


void dfs(int v, vector<int>&vis, vector<vector<int>>&adj,
    map<int,int>&color,map<int,int>&cntCol){
    vis[v] = 1;
    cntCol[color[v]]++;
    mx = max(mx,cntCol[color[v]]);
    cnt++;
    for(auto &x : adj[v]){
        if(!vis[x]){
            dfs(x,vis,adj,color,cntCol);
        }
    }
}

void Solve() {
    int n,m,k;
    cin >>n >> m >> k;
    vector<vector<int>> adj(n+1);
    map<int,int> color;
    for(int i= 1;i<=n;i++){
        int a;
        cin >> a;
        color[i] = a;
    }
    for(int i= 0;i<m;i++){
        int u,v;
        cin >>u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    vector<int> vis(n+1,0);
    int ans = 0;
    for(int i= 1;i<=n;i++){
        if(vis[i] == false){
            map<int,int> cntCol;
            cnt = 0;
            mx = 0;
            dfs(i,vis,adj,color,cntCol);
            ans += cnt-mx;
        }
    }
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