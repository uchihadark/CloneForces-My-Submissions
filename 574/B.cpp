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
    int n,m;
    cin >> n >> m;
    vector<vector<int>>matrix(n,vector<int>(n,0));
    vector<pair<int,int>> edges(m);
    vector<int> degree(n,0);
    for(int i= 0;i<m;i++){
        int u,v;
        cin >> u >> v;
        u--,v--;
        edges[i] = {u,v};
        degree[u]++;
        degree[v]++;
        matrix[u][v] = 1;
        matrix[v][u] = 1;
    }
    int ans = inf;
    for(auto &x : edges){
        int a = x.first;
        int b = x.second;
        for(int i= 0;i<n;i++){
            if(i != a && i != b){
                if(matrix[i][a] && matrix[i][b]){
                    ans = min(ans,degree[a]-2+degree[b]-2+degree[i]-2);
                }
            }
        }
    }
    if(ans == inf)ans = -1;
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