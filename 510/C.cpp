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

int ans = 0;

void dfs(int v,vector<vector<int>>&adj,vector<bool>&vis, string &ans){
    vis[v] = 1;
    for(auto &x : adj[v]){
        if(!vis[x]){
            dfs(x,adj,vis,ans);
        }
    }
    ans.push_back('a'+v);
}


bool cycle(int v, vector<vector<int>>&adj,vector<bool>&vis, vector<bool>&st){
    vis[v] = 1;
    st[v] = 1;
    for(auto &x : adj[v]){
        if(vis[x] == false && cycle(x,adj,vis,st))return true;
        else if(st[x])return true;
    }
    st[v] = false;
    return false;
}


void Solve(){
    int n;
    cin>>n;
    vector<vector<int>>adj(26);
    vector<string> v(n);
    for(int i = 0;i< n;i++){
        cin >> v[i];
    }
    
    for(int i= 1;i<n;i++){
        int j = 0, k = 0;
        bool done = 0;
        while(k < v[i-1].size() && j < v[i].size()){
            if(v[i-1][k] != v[i][j]){
                int from  = v[i-1][k]-'a';
                int to = v[i][j]-'a';
                adj[from].push_back(to);
                done = 1;
                break;
            }
            j++,k++;
        }
        if(done == 0 && k < v[i-1].size() && j == v[i].size()){
            cout << "Impossible" << endl;
            return;
        }
    }

    vector<bool>vis(26,0),st(26,0);
    for(int i= 0;i<26;i++){
        if(vis[i] == 0){
            if(cycle(i,adj,vis,st)){
                cout << "Impossible" << endl;
                return;
            }
        }
    }
    for(int i =0;i<26;i++){
        vis[i] = 0;
    }
    
    string ans;
    for(int i= 0;i<26;i++){
        if(vis[i] == false){
            dfs(i,adj,vis,ans);
        }
    }
    reverse(all(ans));
    cout << ans << endl;
    
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