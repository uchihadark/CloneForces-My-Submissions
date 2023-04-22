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

void dfs(int v, vector<vector<pair<int,pi>>>&adj,vector<int>&vis,
    map<int,pi>&dis,map<int,int>&cnt,vector<int>&path){
    vis[v] = 1;
    path.push_back(dis[v].second);


    //bin search
    if(dis[v].second <= dis[v].first){
        cnt[v] = sz(path)-1;
    }else{
        auto it = lower_bound(all(path),dis[v].first);
        if(*it > dis[v].first){
            cnt[v]=it-path.begin()-1;
        }else{
            cnt[v]=it - path.begin();
        }
    }


    for(auto &x : adj[v]){
        if(vis[x.first] == false){
            dis[x.first].first += x.second.first+dis[v].first;
            dis[x.first].second += x.second.second+dis[v].second;
            dfs(x.first,adj,vis,dis,cnt,path);
        }
    }
    path.pop_back();
}

void Solve() {
    int n;
    cin >> n ;
    vector<vector<pair<int,pi>>> adj(n+1);
    map<int,int> par;
    par[1] = -1;
    for(int i= 2;i<=n;i++){
        int p, a, b;
        cin >> p >> a >> b;
        adj[p].pb({i,{a,b}});
        adj[i].pb({p,{a,b}});
        par[i] = p;
    }
    map<int,pi> dis;
    vector<int> vis(n+1,0);
    map<int,int> cnt;
    vector<int> path;
    dfs(1,adj,vis,dis,cnt,path);
    for(int i= 2;i<=n;i++){
        cout << cnt[i]<<" ";
    }
    cout <<endl;

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