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


string fun(int i, int j, string s) {
    string left = "";
    string right = "";
    while (i < j) {
        if (s[i] == s[j]) {
            left.pb(s[i++]);
            right.pb(s[j--]);
        } else {
            break;
        }
    }
    reverse(all(right));
    string tmp1 = "", tmp2 = "";
    for (int k = i; k <= j; k++) {
        if (s[i] == s[k]) {
            string tmp = s.substr(i, k - i + 1);
            string tmpp = tmp;
            reverse(all(tmp));
            if (tmp == tmpp) {
                tmp1 = tmp;
            }
        }
    }
    for (int k = j; k >= i; k--) {
        if (s[j] == s[k]) {
            string tmp = s.substr(k, j - k + 1);
            string tmpp = tmp;
            reverse(all(tmp));
            if (tmp == tmpp) {
                tmp2 = tmp;
            }
        }
    }
    if (sz(tmp1) > sz(tmp2)) {
        string ans = left + tmp1 + right;
        return ans;
    } else {
        string ans = left + tmp2 + right;
        return ans;
    }

}

void Solve() {
    string s;
    cin >> s;
    int n = sz(s);
    string tmp1 = "", tmp2 = "";
    int i = 0;
    for (int k = i; k < n; k++) {
        if (s[i] == s[k]) {
            string tmp = s.substr(i, k - i + 1);
            string tmpp = tmp;
            reverse(all(tmp));
            if (tmp == tmpp) {
                tmp1 = tmp;
            }
        }
    }
    int j = n - 1;
    for (int k = j; k >= 0; k--) {
        if (s[j] == s[k]) {
            string tmp = s.substr(k, j - k + 1);
            string tmpp = tmp;
            reverse(all(tmp));
            if (tmp == tmpp) {
                tmp2 = tmp;
            }
        }
    }
    if (n == 1) {
        cout << s << endl;
        return;
    }

    string ans1 = "";
    if (sz(tmp1) > sz(tmp2)) {
        ans1 = tmp1;
    } else {
        ans1 = tmp2;
    }

    string ans = fun(0, n - 1, s);
    if (sz(ans) > sz(ans1)) {
        cout << ans << endl;
    } else {
        cout << ans1 << endl;
    }
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