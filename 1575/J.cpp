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
    int n, m, k;
    cin >> n >> m >> k;
    int arr[n][m];
    map<pair<int, int>, int> left, right;
    map < int, set<int>> ll, rr;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 3) {
                left[ {i, j}]++;
            } else if (arr[i][j] == 1) {
                right[ {i, j}]++;
            }
        }
    }
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[j][i] == 1) {
                rr[i].insert(j);
            } else if (arr[j][i] == 3) {
                ll[i].insert(j);
            }
        }
    }
    for (int i = 0; i < k; i++) {
        pi cur;
        int c ;
        cin >> c;
        c--;
        cur = {0, c};
        while (1) {
            // cout << cur.first + 1 << " " << cur.second + 1 << endl;
            if (left.count(cur) == true) {
                left.erase(cur);
                cur.second--;
            } else if (right.count(cur) == true) {
                right.erase(cur);
                cur.second++;
            } else {
                auto it1 = ll[cur.second].lower_bound(cur.first);
                auto it2 = rr[cur.second].lower_bound(cur.first);

                bool f1 = 0, f2 = 0;
                int pos1 = inf;
                if (it1 != ll[cur.second].end()) {
                    pos1 = *it1;
                    f1 = 1;
                }
                int pos2 = inf;
                if (it2 != rr[cur.second].end()) {
                    pos2 = *it2;
                    f2 = 1;
                }
                int req = inf;
                if (f1) {
                    req = pos1;
                }
                if (f2) {
                    req = min(req, pos2);
                }
                if (f1 == 0 && f2 == 0) {
                    cout << cur.second + 1 << " ";
                    break;
                }
                if (req == pos1) {
                    ll[cur.second].erase(it1);
                } else if (req == pos2) {
                    rr[cur.second].erase(it2);
                }
                cur.first = req;
            }

        }

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