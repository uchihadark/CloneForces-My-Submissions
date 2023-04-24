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
    deque<int> d1, d2;
    map<pair<int,int>,pair<int,int>>check;
    map<pair<int,int>,pair<vi,vi>> turn;
    
    int ans = 0;
    int k;
    cin >>k;
    for(int i =0;i<k;i++){
        int a;
        cin >> a;
        d1.push_back(a);
    }
    cin >> k;
    for(int i= 0;i<k;i++){
        int a;
        cin >> a;
        d2.push_back(a);
    }
    
    while(d1.empty() ==false && d2.empty() == false){
        ans++;
        
        int curd1 = d1.front();
        int curd2 = d2.front();
        
        vector<int> v1(d1.begin(),d1.end());
        vector<int> v2(d2.begin(),d2.end());
        
        //cycle 
        if(check.count({curd1,curd2})){
            if(check[{curd1,curd2}] == make_pair(sz(d1),sz(d2)) && turn[{curd1,curd2}].first == v1 
             && turn[{curd1,curd2}].second == v2 ){
                cout << -1 <<endl;
                return;
            }
        }
        check[{curd1,curd2}] = {sz(d1),sz(d2)};
        turn[{curd1,curd2}].first = v1,turn[{curd1,curd2}].second = v2;
        d1.pop_front();
        d2.pop_front();
        if(curd1 > curd2){
            d1.push_back(curd2);
            d1.push_back(curd1);
        }else{
            d2.push_back(curd1);
            d2.push_back(curd2);
        }
    }
    cout << ans <<" ";
    if(d1.empty()){
        cout << 2 <<endl;
    }else{
        cout << 1 <<endl;
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