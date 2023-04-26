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

int gcd(int a, int b){if (b == 0) return a;return gcd(b, a % b);}

void Solve() {
    int a, b;
    cin >> a >> b;
    int _gcd = gcd(a,b);

    int diff = abs((a/_gcd)-(b/_gcd));
    if(diff == 1){
        cout <<"Equal\n";
    }else if(a < b){
        cout <<"Dasha\n";
    }else{
        cout <<"Masha\n";
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