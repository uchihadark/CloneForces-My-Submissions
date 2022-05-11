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

map<string, int> cnt;
void compute() {
    int cur = 1;
    for (char i = 'a'; i <= 'z'; i++) {
        for (char j = 'a'; j <= 'z'; j++) {
            if (i == j)continue;
            else {
                string tmp;
                tmp.pb(i);
                tmp.pb(j);
                cnt[tmp] = cur;
                cur++;
            }
        }
    }
}

void Solve() {
    string s;
    cin >> s;
    cout << cnt[s] << endl;
}

int32_t main() {
    FAST_IO
    int TC = 1;
    cin >> TC;
    compute();
    while (TC--) {
        Solve();
    }
    TIME
}