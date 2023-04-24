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
    int a, b;
    cin >> a >> b;
    
    queue<pair<pi,int>>q;
    q.push({{a,b},0});
    map<pi,bool>vis;
    vector<int>op = {2,3,5};
    while(q.empty() == false){
        int cura = q.front().first.first;
        int curb = q.front().first.second;
        int cnt = q.front().second;
        
        q.pop();
        if(cura == curb){
            cout << cnt <<endl;
            return;
        }
        
        for(int i = 0;i<3;i++){
            for(int j = 0;j<3;j++){
                int curaa = cura;
                int curbb = curb;
                int curcnt = 0;
                if(curaa%op[i] == 0){
                    curaa /= op[i]; 
                    curcnt++;
                    if(vis.count({curaa,curb}) == false){
                        q.push({{curaa,curb},cnt+1});
                        vis[{curaa,curb}] = 1;
                    }
                }
                if(curbb%op[j] == 0){
                    curbb /= op[j];
                    curcnt++;
                    if(vis.count({cura,curbb}) == false){
                        q.push({{cura,curbb},cnt+1});
                        vis[{cura,curbb}] = 1;
                    }
                }
                if(vis.count({curaa,curbb}) == false){
                    q.push({{curaa,curbb},cnt+curcnt});
                    vis[{curaa,curbb}] = 1;
                }
            }
        }

    }
    cout << -1 <<endl;
    
    
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