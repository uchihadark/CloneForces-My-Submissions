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
    int primes[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31};
    int n;
    cin >> n;
    vector<int> v(n);
    for (auto &x : v) {
        cin >> x;
    }
    set<int> s;
    for (auto &x : v) {
        for (int i = 0; i < 11; i++) {
            if (x % primes[i] == 0) {
                x = primes[i];
                s.insert(primes[i]);
                break;
            }
        }
    }
    map<int, int> cnt;
    int cn = 1;
    for (auto &x : s) {
        cnt[x] = cn;
        cn++;
    }
    cout << sz(s) << endl;
    for (auto &x : v) {
        cout << cnt[x] << " ";
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