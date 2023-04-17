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
    int n, m;
    cin >> n>> m;
    vector<vector<int>> adj(n+1);
    for(int i= 0;i<m;i++){
        int u, v;
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // bus
    int s = 0;
    int d = 0;
    for(int i= 1;i<=n;i++){
        if(sz(adj[i]) == 1)s++;
        else if(sz(adj[i]) == 2)d++;
    }
    if(s == 2 && d == n-2){
        cout << "bus topology";
        return;
    }

    //ring
    if(d == n){
        cout <<"ring topology";
        return;
    }

    //star
    s = 0;
    d = 0;
    for(int i= 1;i<=n;i++){
        if(sz(adj[i]) == n-1)s++;
        else if(sz(adj[i]) == 1)d++;
    }
    if(s == 1 && d == n-1){
        cout << "star topology";
        return;
    }
    cout << "unknown topology";
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