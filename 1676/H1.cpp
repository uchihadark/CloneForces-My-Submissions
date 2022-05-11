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

bool sortbysec(const pair<int, int> &a,
               const pair<int, int> &b)
{
    return (a.second < b.second);
}

void Solve() {
    int n;
    cin >> n ;
    vi v(n);
    vector<pi> arr;
    for (int i = 0; i < n; i++) {
        cin >>  v[i];
        v[i]--;
        arr.pb({i, v[i]});
    }
    int ans = 0;
    sort(all(arr), sortbysec);
    // for (int i = 0; i < n; i++) {
    //     cout << arr[i].first << " " << arr[i].second << ", ";
    // }
    // cout << endl;
    for (int i = 0; i < n; i++) {
        for (int j  = 0; j < n; j++) {
            if (i == j)continue;
            if (arr[j].first < arr[i].first  && arr[j].second  >= arr[i].second) {
                ans++;
            }
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