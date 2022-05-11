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
    int n , m;
    cin >> n >> m;
    string s[n];
    for (int i = 0; i < n; i++) {
        cin >> s[i];
    }
    for (int i = 0; i < m; i++) {
        vector<pi> obs;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (s[j][i] == '*')cnt++;
            if (s[j][i] == 'o') {
                obs.pb({j, cnt});
                cnt = 0;
            }
        }
        if (sz(obs) == 0) {
            for (int j = n - 1; j >= 0; j--) {
                if (cnt > 0) {
                    s[j][i] = '*';
                    cnt--;
                } else {
                    s[j][i] = '.';
                }
            }
        } else {
            for (auto &val : obs) {
                int ind = val.first;
                int cn = val.second;
                for (int j = ind - 1; j >= 0; j--) {
                    if (s[j][i] == 'o') {
                        break;
                    }
                    if (cn > 0) {
                        s[j][i] = '*';
                        cn--;
                    } else {
                        s[j][i] = '.';
                    }
                }
            }
            for (int j = n - 1; j >= 0; j--) {
                if (s[j][i] == 'o') {
                    break;
                }
                if (cnt > 0) {
                    s[j][i] = '*';
                    cnt--;
                } else {
                    s[j][i] = '.';
                }
            }

        }
    }

    for (int i = 0; i < n; i++) {
        cout << s[i] << endl;
    }
    cout << endl;

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