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
void solve() {
    double n, k;
    cin >> n >> k;
    double  d, s;
    cin >> d >> s;
    double ans = (d * n - s * k) / (n - k);
    if (ans >= 0 && ans <= 100) printf("%.6f", ans);
    else cout << "impossible";
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int t = 1;
    //cin >> t;
    while (t--) solve();
}