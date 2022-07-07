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

bool palindrome(int i , int j , string s) {
    while (i <= j) {
        if (s[i++] != s[j--]) {
            return false;
        }
    }
    return true;
}

void Solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int ans = 0;
    int i = 0;
    while (i + 1 < n) {
        if (s[i] == '(' || (s[i] == ')' && s[i + 1] == ')')) {
            i += 2;
        } else {
            int j = i + 1;
            while (j < n && s[j] != ')') {
                j++;
            }
            if (j == n) {
                break;
            }
            i = j + 1;
        }
        ans++;
    }
    cout << ans << " " << n - i << endl;
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