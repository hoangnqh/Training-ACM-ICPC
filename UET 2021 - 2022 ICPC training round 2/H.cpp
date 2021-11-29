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
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++) {
        cin >> arr[i];
    }
    int ans[n];
    sort(arr + 0, arr + n);
    int l = 0, r = n - 1;
    for (int i = n - 1; i >= 0; i--) {
        if (i % 2) {
            ans[i] = arr[l];
            l++;
        }
        else {
            ans[i] = arr[r];
            r--;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << ans[i] << " ";
    }
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