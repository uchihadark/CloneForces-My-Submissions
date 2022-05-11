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

bool isSubSequence(string str1, string str2, int m, int n)
{

    // Base Cases
    if (m == 0)
        return true;
    if (n == 0)
        return false;

    // If last characters of two
    // strings are matching
    if (str1[m - 1] == str2[n - 1])
        return isSubSequence(str1, str2, m - 1, n - 1);

    // If last characters are
    // not matching
    return isSubSequence(str1, str2, m, n - 1);
}

void Solve() {
    string s, t;
    cin >> s;
    t = "heidi";
    if (isSubSequence(t, s, sz(t), sz(s))) {
        cout << "YES";
    } else {
        cout << "NO\n";
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