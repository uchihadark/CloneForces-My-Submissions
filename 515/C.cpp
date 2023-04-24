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
    int n;string a;
    cin >> n >> a;

    vector<int>primes = {2,3,5,7};
    vector<int> ans;
    int cnt2 = 0, cnt3 = 0;
    bool found = 0;
    for(auto &x : a){
        int num = x-'0';
        bool isPrime = 0;
        for(auto &y : primes){
            if(y == num){
                isPrime = 1;
                ans.push_back(num);
            }
        }
        if(isPrime==false){
            if(num == 9){
                cnt3 += 2;
                cnt2 += 3;
                ans.push_back(7);
            }else if(num == 8){
                cnt2 += 3;
                ans.push_back(7);
            }else if(num == 6){
                cnt2++,cnt3++;
                ans.push_back(5);
            }else if(num == 4){
                cnt2 += 2;
                ans.push_back(3);
            }
            found = 1;
        }
    }
    if(found ==0){
        sort(all(a));
        reverse(all(a));
        cout << a <<endl;
    }else{
        for(int i=0;i<cnt3;i++){
            ans.push_back(3);
        }
        cnt2 -=cnt3;
        for(int i= 0;i<cnt2;i++){
            ans.push_back(2);
        }
        sort(all(ans));
        reverse(all(ans));
        for(auto &x : ans)cout << x;
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