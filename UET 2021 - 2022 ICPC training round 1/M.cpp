#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first 
#define se second 
#define mp make_pair 
#define pb push_back 
typedef pair<int, int >ii;
typedef pair<int, ii> iii;
const int INF = 1e10;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
typedef tuple<int, int, char> tiic;
double a[200];
void solve() {
    double n, vb, vs;
    cin >> n >> vb >> vs;
    double x, y;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    cin >> x >> y;
    double t = INF;
    int res = 2;
    for (int i = 1; i < n; i++) {
        double tmp = (x - a[i]) * (x - a[i]) + y * y;
        tmp = sqrt(tmp);
        tmp = tmp * vb + a[i] * vs;
        if (tmp <= t) {
            res = i + 1;
            t = tmp;
        }
    }
    cout << res;
}
 
int32_t main() {
 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
}