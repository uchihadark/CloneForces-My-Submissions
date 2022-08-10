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
    int a,b;
    cin>> a >> b;
    if(a > b){
        swap(a,b);
    }
    if(a == b){
        cout << 0 <<endl;
        return;
    }
    int diff = b-a;
    int i =1;
    for(i = 1;;i++){
        int cur = i*(i+1)/2;
        if(cur == diff){
            cout << i << endl;
            return;
        }
        if(cur > diff){
            if(cur %2 == diff%2 ){
                cout << i << endl;
                return;
            }
        }
    }
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