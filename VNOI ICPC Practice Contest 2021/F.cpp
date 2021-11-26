#include<bits/stdc++.h>
using namespace std;

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
const int N = 1e4 + 5;

int n, u, v;
int a[N], sum[N];

void solve(){
    cin >> n >> u >> v;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    if(u > v) swap(u, v);
    sort(a + 1, a + n + 1);
    for(int i = 1; i <= n; i++){
        sum[i] = sum[i - 1] + a[i];
    }

    int l = 1, r = 1e6;
    int res = 1e6;
    while(l <= r){
        int m = (l + r) / 2;
        int s = 0;
        for(int i = n; i >= 1; i--){
            int tg = (s + a[i] - 1) / v + 1;
            if(tg <= m) s += a[i];
        }
        int s2 = sum[n] - s;
        int tg = (s2 - 1) / u + 1;
        if(tg <= m){
            res = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    cout << res << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T; while(T--)
    solve();
}
