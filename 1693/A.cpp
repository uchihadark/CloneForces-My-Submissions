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
    vi v(n);
    for (int i = 0; i < n; i++) {
        cin >> v[i];
    }
    if (n == 1) {
        if (v[0] == 0) {
            cout << "YES\n";
        } else {
            cout << "NO\n";
        }
        return;
    }
    int lstInd = -1;
    for (int i = 0; i < n; i++) {
        if (v[i] == 0) {
            int ind = i;
            while (ind < n && v[ind] == 0) {
                ind++;
            }
            if (ind == n) {
                lstInd = max(0LL, i - 1);
                break;
            } else {
                ind--;
                i = ind;
            }
        }
    }
    if (v[n - 1] != 0) {
        lstInd = n - 1;
    }
    if (lstInd == 0) {
        if (v[0] != 0) {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        return;
    }
    if (v[lstInd] > 0) {
        cout << "NO\n";
        return;
    }
    vi ans(lstInd, 1);
    // cout << lstInd << endl;
    int req = abs(v[lstInd]);
    req--;
    lstInd--;
    while (lstInd >= 0) {
        int cur = ans.back();
        ans.pop_back();
        cur += req;
        if (v[lstInd] > cur) {
            cout << "NO\n";
            return;
        }
        req = cur - v[lstInd];
        if (req == 0 && lstInd != 0) {
            cout << "NO\n";
            return;
        }
        lstInd--;
        req--;
        if (lstInd == -1) {
            if (req == -1) {
                req = 0;
            }
        }
    }
    if (req != 0) {
        cout << "NO\n";
        return;
    }
    cout << "YES\n";

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