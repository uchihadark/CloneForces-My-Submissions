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
    int arr[n + 1];
    map<int, int> prsnt;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        if (arr[i] != 0) {
            prsnt[arr[i]]++;
        }
    }
    vi commonInd, commonVal;
    vi indList, valList;
    for (int i = 1; i <= n; i++) {
        if (arr[i] == 0) {
            if (prsnt.count(i) == false) {
                commonVal.pb(i);
                commonInd.pb(i);
                continue;
            } else {
                indList.pb(i);
            }
        }
        if (prsnt.count(i) == false) {
            valList.pb(i);
        }
    }

    if (sz(commonInd) > 0) {
        sort(all(commonInd));
        sort(all(commonVal));
    } else {
        for (int i = 0; i < sz(indList); i++) {
            arr[indList[i]] = valList[i];
        }
        for (int i = 1; i <= n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        return;
    }
    if (sz(commonInd) == 1) {
        arr[indList[0]] = commonVal[0];
        arr[commonInd[0]] = valList[0];
        for (int i = 1; i < sz(indList); i++) {
            arr[indList[i]] = valList[i];
        }
        for (int i = 1; i <= n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
    } else {
        for (int i = 0; i < sz(commonInd) - 1; i++) {
            arr[commonInd[i]] = commonVal[i + 1];
        }
        arr[commonInd[sz(commonInd) - 1]] = commonVal[0];
        for (int i = 0; i < sz(indList); i++) {
            arr[indList[i]] = valList[i];
        }
        for (int i = 1; i <= n; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
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