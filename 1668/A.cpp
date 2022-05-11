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
    int r, c;
    cin >> r >> c;
    if (r > c) {
        swap(r, c);
    }
    if (r * c == 1) {
        cout << 0 << endl;
        return;
    }
    if (r == c) {
        cout << (r - 1) + (c - 1) << endl;
        return;
    }
    if (r == 1 && c > 2) {
        cout << -1 << endl;
        return;
    }
    int count = r + (r - 1);
    int diff = c - ( r + 1);
    if (diff % 2 == 0) {
        int half = diff / 2;
        count += half * 3;
        count += half;
    } else {
        if (diff == 1) {
            count += 3;
        } else {
            int half = diff / 2;
            count += half * 3;
            count += half;
            count += 3;
        }
    }
    cout << count << endl;
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