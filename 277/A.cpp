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

void dfs(int v, vector<int>&vis,vector<vector<int>>&adj){
    vis[v] = 1;
    for(auto &x : adj[v]){
        if(vis[x] == false){
            dfs(x,vis,adj);
        }
    }
}

void Solve() {
    int n,m;
    cin >> n >> m;
    int cnt = 0;
    vector<vector<int>> adj(n+1);
    vector<vector<int>>lang(m+1);
    for(int i=0;i<n;i++){
        int x;
        cin >> x;
        if(x == 0)cnt++;
        while(x--){
            int a;
            cin >> a;
            lang[a].push_back(i+1);
        }
    }
    for(int i= 1;i<=m;i++){
        for(int j = 0;j<lang[i].size();j++){
            for(int k = j+1;k<lang[i].size();k++){
                adj[lang[i][j]].push_back(lang[i][k]);
                adj[lang[i][k]].push_back(lang[i][j]);
            }
        }
    }



    vector<int> vis(n+1,0);
    int ans = 0;
    for(int i= 1;i<=n;i++){
        if(vis[i] == false){
            dfs(i,vis,adj);
            ans++;
        }
    }
    cout << max(ans-1,cnt) << endl;


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