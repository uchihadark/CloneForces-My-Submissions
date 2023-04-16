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

    map<int,int>cnt;
    for(int i = 2;i*i<=n;i++){
        if(n%i == 0){
            while(n%i == 0){
                cnt[i]++;
                n /= i;
            }
        }
    }
    if(n != 1){
        cnt[n]++;
    }
    vector<pair<int,int>> primes;
    for(auto &x : cnt){
        // cout << x.first <<" "<< x.second << endl;
        primes.pb({x.second,x.first});
    }
    sort(all(primes));
    int ans = 0;
    for(int i =0;i<primes.size();i++){
        int cur = primes[i].second;
        int freq = cnt[cur];
        for(int j = i+1;j<primes.size();j++){
            cur *= primes[j].second;
            cnt[primes[j].second] -= freq;
        }
        ans += cur*freq;
        if(cnt[primes[0].second] == 0)break;

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