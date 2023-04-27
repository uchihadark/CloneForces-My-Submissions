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

int m;
vector<vector<int>>adj(200005);
map<int,int>cat;

int valid = 0;

vector<int>vis(200005,0);
void dfs(int v,int cnt){
    vis[v] = 1;
    if(cat[v] == 0){
        cnt = 0;
    }else{
        cnt++;
    }
    // cout << v+1 <<" "<< cnt <<endl;
    if(cnt > m)return;
    bool leaf = 1;
    for(auto &x : adj[v]){
        if(vis[x] == 0){
            dfs(x,cnt);
            leaf = 0;
        }
    }
    if(leaf == 1 && cnt <= m){
        valid++;
    }
    cnt -= cat[v];
}

void Solve() {
   int n;
   cin >> n >> m;
   for(int i= 0;i<n;i++){
       int cur;
       cin >> cur;
       cat[i] = cur;
   }
   for(int i= 0;i<n-1;i++){
       int u,v;
       cin >> u >> v;
       u--,v--;
       adj[u].pb(v);
       adj[v].pb(u);
   }
   dfs(0,0);
   cout << valid <<endl;
   
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