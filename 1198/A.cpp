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
    int n, I;
    cin >> n >> I;
    int totalBits = I * 8;
    map<int, int> freq;
    vi v(n);
    vi order;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        freq[v[i]]++;
        if (freq[v[i]] == 1) {
            order.pb(v[i]);
        }
    }
    vector<int> pre;
    int cur = 1;
    while (cur <= 1e9) {
        pre.pb(cur);
        cur *= 2;
    }
    sort(all(order));
    int num = sz(order);
    int cnt = 1;
    int req = 0;
    while (1) {
        int curBits = 0;
        auto it = lower_bound(all(pre), cnt);
        int ind = it - pre.begin();
        curBits += ind * (n);
        if (curBits <= totalBits) {
            req = cnt;
        } else {
            break;
        }
        if (req >= sz(order)) {
            cout << 0 << endl;
            return;
        }
        cnt++;
    }
    req = sz(order) - req;
    int fromStart = 0;
    int fromEnd = 0;
    for (int i = 0; i < req; i++) {
        fromStart += freq[order[i]];
    }
    int ans = inf;
    ans = min(ans, fromStart);
    for (int i = sz(order) - 1; i > sz(order) - 1 - req; i--) {
        fromEnd += freq[order[i]];
    }
    ans = min(fromEnd, ans);
    int curCnt = 0;

    int cur1 = req;
    int cur2 = 0;
    vi pres(sz(order), 0), suf(sz(order), 0);
    for (int i = 0; i < sz(order); i++) {
        if (i == 0) {
            pres[i] = freq[order[i]];
        } else {
            pres[i] = pres[i - 1] + freq[order[i]];
        }
    }
    for (int i = sz(order) - 1; i >= 0; i--) {
        if (i == sz(order) - 1) {
            suf[i] = freq[order[i]];
        } else {
            suf[i] = suf[i + 1] + freq[order[i]];
        }
    }

    while (cur2 <= req) {
        curCnt = 0;
        if (cur1 - 1 >= 0) {
            curCnt += pres[cur1 - 1];
        }
        if (sz(order) - cur2 <  n) {
            curCnt += suf[sz(order) - cur2];
        }
        ans = min(curCnt, ans);
        cur1--;
        cur2++;
    }

    cout << ans << endl;



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