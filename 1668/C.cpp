#include "bits/stdc++.h"
using namespace std;
#define int long long
#define pb push_back
#define sz(x) (int)(x).size()
#define all(x) (x).begin(),(x).end()
#define forn(i,n) for(int i=0;i<(n);++i)

int32_t main() {
    cin.tie(0)->sync_with_stdio(0);
    int n; cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    int ans = 9e18;
    for (int x = 0; x < n; ++x) {
        // make b[x] = 0;
        vector<int> b(n);
        int c = 0;
        for (int i = x - 1; ~i; --i) {
            if (b[i] >= b[i + 1]) {
                int x = (b[i] - b[i + 1]) / a[i];
                while (b[i + 1] <= b[i] - x * a[i])
                    x++;
                c += x;
                b[i] -= x * a[i];
            }
        } for (int i = x + 1; i < n; ++i) {
            if (b[i] <= b[i - 1]) {
                int x = (b[i - 1] - b[i]) / a[i];
                while (b[i - 1] >= b[i] + x * a[i])
                    x++;
                c += x;
                b[i] += x * a[i];
            }
        }
        ans = min(ans, c);
    }
    cout << ans << '\n';
}
