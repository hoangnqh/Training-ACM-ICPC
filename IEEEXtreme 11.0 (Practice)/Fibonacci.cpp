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
int fibon[100];
void solve() {
    int m;
    
    cin >> m;
    m %= 60;
    cout << fibon[m] << '\n';

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    fibon[0] = 1;
    fibon[1] = 1;
    for (int i = 2; i <= 70; i++) {
        fibon[i] = (fibon[i - 1] + fibon[i - 2]) % 10;
    }
    // cout << fibon[60] << " " << fibon[61];
    int t = 1;
    cin >> t;
    while (t--) {
        solve();
    }
}
