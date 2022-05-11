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
    priority_queue<int> pq;
    for (int i = 0; i < n; i++) {
        cin >> v[i];
        pq.push(v[i]);
    }
    int turn = 0;
    while (!pq.empty()) {
        int cur = pq.top();
        pq.pop();
        if (cur == 1) {
            if (turn == 0) {
                cout << "maomao90\n";
                return;
            } else {
                cout << "errorgorn\n";

                return;
            }
        }
        if (cur % 2 == 0) {
            pq.push(cur / 2);
            pq.push(cur / 2);
            if (turn == 0) {
                turn = 1;
            } else {
                turn = 0;
            }
        } else {
            pq.push(cur / 2);
            pq.push(cur / 2 + 1);
            if (turn == 0) {
                turn = 1;
            } else {
                turn = 0;
            }
        }
    }
    cout << "maomao90\n";


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