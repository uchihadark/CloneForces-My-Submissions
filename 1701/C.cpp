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
    map<int,int> cnt;
    vector<int> v(m);
    for(int i= 0;i<m;i++){
        cin >> v[i];
        v[i]--;
        cnt[v[i]]++;
    }
    auto check = [&](int time){
        int extra = 0, need = 0;
        for(int i= 0;i<n;i++){
            if(time >= cnt[i]){
                extra += (time-cnt[i])/2;
            }else{
                need += cnt[i]-time;
            }
        }
        return need <= extra;
    };
    int ans = -1;

    int low = 0, high = 2*m;
    while(low <= high){
        int mid = (low+high)/2;
        if(check(mid)){
            ans = mid;
            high = mid-1;
        }else{
            low = mid+1;
        }
    }
    cout << ans << endl;

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