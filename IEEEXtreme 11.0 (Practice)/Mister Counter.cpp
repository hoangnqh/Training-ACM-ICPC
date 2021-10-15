#include<bits/stdc++.h>
using namespace std;

#define int long long

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ld long double

typedef pair<int, int> II;
typedef pair<int, II> III;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

const int INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 250000 + 5;

int n, q;
int a[N];
int d[N];

void query(int u, int v){
    int l = u, r = v, res = u;
    while(l <= r){
        int m = (l + r) / 2;
        int val = m + d[m] - 1;
        if(val >= v){
            res = m;
            r = m - 1;
        }
        else{
            l = m + 1;
        }
    }
    if(res == u){
        cout << 0 << '\n';
        return;
    }

    int val = v - res + 1;
    int mid = res + (val / 2);
    if(val % 2 && val > 2 &&
    ((a[res - 1] > a[mid]) || (a[res - 1] < a[mid] && a[mid + 1] > a[res - 1]))){
        val -= 1;
    }
    cout << val + 1 << '\n';
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    d[n] = 1;
    for(int i = n - 1; i >= 1; i--){
        if(a[i] > a[i + 1]) d[i] = d[i + 1] + 1;
        else d[i] = 1;
    }

    cin >> q;
    for(int i = 1; i <= q; i++){
        int u, v;
        cin >> u >> v;
        query(u, v);
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
