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
    int c, n;
    cin >> c >> n;
    int d[n + 1][c + 1];
    ii a[n + 1];
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se;
    }
    for (int i = 0; i <= c; i++) {
        d[0][i] = 0;
    }
    for (int i = 0; i <= n; i++) {
        d[i][0] = 0;
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= c; j++) {
            if (a[i].fi <= j) {
                d[i][j] = max(d[i - 1][j], d[i - 1][j - a[i].fi] + a[i].se);
            }
            else d[i][j] = d[i - 1][j];
        }
    }
    cout << d[n][c] << '\n';

}
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
