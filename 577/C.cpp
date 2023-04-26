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

bool isPrime(int n){
    for(int i= 2;i*i<=n;i++){
        if(n%i == 0)return false;
    }
    return true;
}

void Solve() {
    int n;
    cin >> n;

    set<int> primes;
    for(int i = 2;i<=n;i++){
        if(isPrime(i)){
            primes.insert(i);
        }
    }
    vector<int> ans;
    for(int i=2;i<=n;i++){
        if(primes.count(i)){
            ans.push_back(i);
            continue;
        }else{
            int cnt =0;
            bool added = 0;
            for(auto &x : primes){
                if(i%x == 0){
                    cnt++;
                }
            }
            if(cnt == 1){
                ans.pb(i);
            }
        }

    }
    cout << sz(ans)<<endl;
    for(auto &x : ans){
        cout << x<<" ";
    }
    cout <<endl;
    
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