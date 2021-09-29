#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first 
#define se second 
#define mp make_pair 
#define pb push_back 
typedef pair<int, int >ii;
typedef pair<int, ii> iii;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> res;
    if (n <= 2) {
        cout << 1 << '\n';
        cout << n << '\n';
        return;
    }
    int tmp = (n - 3) / 4;
    if (tmp * 4 + 3 == n - 3) {
        for (int i = 2; i <= n; i++) {
            res.pb(i);
        }
    }
    else {
        for (int i = 1; i <= 3 + 4 * tmp; i++) {
            res.pb(i);
        }
        if (n != res[res.size() - 1]) res.pb(n);
        else {
            res.pop_back();
        }
    }
    cout << res.size() << '\n';
    for (auto x : res) {
        cout << x << " ";
    }
    cout << '\n';
    // int res = 6;
    // for (int i = res + 1; i <= 9; i++) {
    //     res = res xor i;
    // }
    // cout << res;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }

}