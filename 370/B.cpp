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
    int n;
    cin >>n;
    vector<vector<int>>v(n,vector<int>(101,0));
    for(int i= 0;i<n;i++){
        int m;
        cin >> m;
        for(int j = 0;j<m;j++){
            int a;
            cin >> a;
            v[i][a] = 1;
        }
    }

    for(int i= 0;i<n;i++){
        bool flag = 1;
        for(int j = 0;j<n;j++){
            if(i == j)continue;
            int cnt = 0;
            for(int k= 1;k<=100;k++){
                if(v[j][k])cnt++;
            }
            for(int k = 1;k<=100;k++){
                if(v[i][k] && v[j][k])cnt--;
            }
            if(cnt <= 0){
                flag = 0;
            }
        }
        if(flag){
            cout <<"YES\n";
        }else{
            cout <<"NO\n";
        }
    }
    


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