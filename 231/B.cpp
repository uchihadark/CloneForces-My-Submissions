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
    int n, d, l;
    cin >> n >> d >> l;

    int mx = (n / 2) * (l - 1);
    int mn = (n / 2) * (1 - l);

    if (n % 2 != 0) {
        mn++;
        mx += l;
    }
    if (d >= mn && d <= mx) {
        vi ans(n, 0);
        if (n % 2 != 0) {
            if (d <= 0) {
                d--;
                ans[n - 1] = 1;
            } else {
                int num = min(l, d);
                d -= num;
                ans[n - 1] = num;
            }
            n--;
        }
        pair<int, int> p1;
        int rem = 0, num = 0;
        if(l > 1){
        	rem = abs(d) % (l - 1);
	        num = abs(d) / (l - 1);
        }

        for (int i = 1; i <= l; i++) {
            for (int j = 1; j <= l; j++) {
                if (d < 0) {
                    int num = i - j;
                    if (num == -(l - 1)) {
                        p1.first = i;
                        p1.second = j;
                        break;
                    }
                } else {
                    int num = i - j;
                    if (num == (l - 1)) {
                        p1.first = i;
                        p1.second = j;
                        break;
                    }
                }
            }
        }
        pair<int, int> p2;
        for (int i = 1; i <= l; i++) {
            for (int j = 1; j <= l; j++) {
                if (d < 0) {
                    int num = i - j;
                    if (num == -(rem)) {
                        p2.first = i;
                        p2.second = j;
                        break;
                    }
                } else {
                    int num = i - j;
                    if (num == rem) {
                        p2.first = i;
                        p2.second = j;
                        break;
                    }
                }
            }
        }
        int cnt = 0;
        int i = 0;

        for (i = 0; cnt < num && i < n; i += 2) {
            ans[i] = p1.first;;
            ans[i + 1] = p1.second;
            cnt++;
        }
        bool f = 0;
        for (; i < n && f == 0; i += 2) {
            ans[i] = p2.first;
            ans[i + 1] = p2.second;
            f = 1 ;
        }
        for (; i < n; i += 2) {
            ans[i] = 1;
            ans[i + 1] = 1;
        }
        for (auto &val : ans) {
            cout << val << " ";
        }
        cout << endl;

    } else {
        cout << -1 << endl;
        return;
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