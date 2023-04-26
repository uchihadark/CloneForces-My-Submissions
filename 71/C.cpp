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
   cin >> n;
   int nn = n;
   vector<int> v(n);
   for(auto &x : v){
       cin >> x;
   }
   
   vector<int> primeFactor;
   if(n%2 == 0){
       while(n%2 == 0){
           n /= 2;
       }
   }
   for(int i= 3;i*i<=n;i += 2){
       if(n%i == 0){
           primeFactor.pb(i);
           while(n%i == 0){
               n /= i;
           }
       }
   }
   if(n > 2){
       primeFactor.pb(n);
   }
   if(nn%4 == 0){
       primeFactor.pb(4);
   }
    for(auto &x: primeFactor){
    int len = nn/x;
      for(int i= 0;i<len;i++){
          bool found = 1;
          for(int j = i;j<nn;j+=len){
              if(v[j] != 1){
                  found = 0;
                  break;
              }
          }
          if(found){
              cout <<"YES\n";
              return;
          }
      }
   }
    cout <<"NO\n";
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