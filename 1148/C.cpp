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
    vi v(n + 1);
    map<int, int> pos;
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
        pos[v[i]] = i;
    }

    int ind = 1;
    vector<pi> ans;
    while (ind <= n / 2) {
        if (v[ind] == ind) {
            ind++;
        } else {
            if (v[ind] > n / 2) {
                int og = ind;
                int posOg = pos[og];
                if (ind + n / 2 <= posOg) {
                    pos[og] = og;
                    pos[v[ind]] = posOg;
                    ans.pb({ind, posOg});
                    swap(v[ind], v[posOg]);
                } else {
                    if (posOg + n / 2 <= n) {
                        ans.pb({posOg, n});
                        swap(v[posOg], v[n]);
                        ans.pb({ind, n});
                        swap(v[ind], v[n]);
                        pos[v[ind]] = ind;
                        pos[v[posOg]] = posOg;
                        pos[v[n]] = n;
                    } else {
                        ans.pb({posOg, 1});
                        swap(v[posOg], v[1]);
                        ans.pb({1, n});
                        swap(v[1], v[n]);
                        ans.pb({ind, n});
                        swap(v[ind], v[n]);
                        ans.pb({1, posOg});
                        swap(v[1], v[posOg]);
                        pos[v[1]] = 1;
                        pos[v[ind]] = ind;
                        pos[v[posOg]] = posOg;
                        pos[v[n]] = n;
                    }
                }
            } else {
                int ogPosNum = v[v[ind]];
                int lastNum = v[n];
                int curNum = v[ind];
                ans.pb({ind, n});
                ans.pb({curNum, n});

                pos[lastNum] = ind;
                pos[curNum] = curNum;
                pos[ogPosNum] = n;

                v[ind] = lastNum;
                v[curNum] = curNum;
                v[n] = ogPosNum;

            }
        }
    }
    for (int i = n / 2; i <= n; i++) {
        if (v[i] != i) {
            int cur = v[i];
            int og = pos[i];
            ans.pb({1, og});
            ans.pb({1, i});
            ans.pb({1, og});
            v[og] = cur;
            v[i] = i;
            pos[i] = i;
            pos[cur] = og;

        }
    }
    // for (int i = 1; i <= n; i++) {
    //     cout << v[i] << " ";
    // }
    // cout << endl;
    cout << sz(ans) << endl;

    for (auto &val : ans) {
        cout << val.first << " " << val.second << endl;
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