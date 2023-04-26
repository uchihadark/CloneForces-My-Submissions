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
    int n,m,k;
    cin>> n >> m >>k;
    vi v(n);
    for(int i= 0;i<n;i++){
        cin >> v[i];
    }
    map<int,pair<pi,int>> op;
    for(int i= 0;i<m;i++){
        int l, r, d;
        cin >> l >> r >> d;
        l--,r--;
        op[i] = {{l,r},d};
    }
    vector<int>opCount(m,0);
    for(int i= 0;i<k;i++){
        int a, b;
        cin >> a>> b;
        a--,b--;
        opCount[a]++;
        if(b+1 < m){
            opCount[b+1]--;
        }
    }
    for(int i= 1;i<m;i++){
        opCount[i] += opCount[i-1];
    }
    vector<int>res(n,0);
    for(int i= 0;i<m;i++){
        int cnt = opCount[i];
        int l = op[i].first.first;
        int r = op[i].first.second;
        int d = op[i].second;
        res[l] += cnt*d;
        if(r+1 < n){
            res[r+1] -= cnt*d;
        }
    }
    for(int i= 1;i<n;i++){
        res[i] += res[i-1];
    }
    for(int i= 0;i<n;i++){
        v[i] += res[i];
        cout << v[i]<<" ";
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