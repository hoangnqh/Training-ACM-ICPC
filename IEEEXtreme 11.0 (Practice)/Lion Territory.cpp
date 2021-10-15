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
const int N = 1e6 + 5;

int a[3005][3005];
int n, m, k;
II query[N];

void solve(){
    cin >> n >> m >> k;
    for(int i = 1; i <= k; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u += 1000;
        v += 1000;
        query[i] = mp(u, v);
        int u1, v1;

        // 1
        u1 = u, v1 = v - w;
        a[u1][v1] += 1;

        u1 = u + w, v1 = v;
        a[u1 + 1][v1 + 1] -= 1;

        u1 = u - w, v = v;
        a[u1 - 1][v1 + 1] -= 1;

        u1 = u - 1, v1 = v + w + 1;
        a[u1 + 1][v1 + 1] += 1;

        if(w == 0) continue;
        // 2
        w -= 1;

        u1 = u, v1 = v - w;
        a[u1][v1] += 1;

        u1 = u + w, v1 = v;
        a[u1 + 1][v1 + 1] -= 1;

        u1 = u - w, v = v;
        a[u1 - 1][v1 + 1] -= 1;

        u1 = u - 1, v1 = v + w + 1;
        a[u1 + 1][v1 + 1] += 1;
    }

    n = 3000, m = 3000;

    int u = 1, v = m;
    while(u <= n){
        int u1 = u, v1 = v;
        while(u1 <= n && v1 <= m){
            a[u1][v1] += a[u1 - 1][v1 - 1];
            u1 += 1;
            v1 += 1;
        }
        if(v == 1){
            u += 1;
        }
        else v -= 1;
    }

    u = 1, v = 1;
    while(v <= m){
        int u1 = u, v1 = v;
        while(u1 >= 1 && v1 <= m){
            a[u1][v1] += a[u1 + 1][v1 - 1];
            u1 -= 1;
            v1 += 1;
        }
        if(u == n){
            v += 1;
        }
        else u += 1;
    }


    II res = mp(0, 0);
    for(int i = 1; i <= k; i++){
        int u = query[i].fi, v = query[i].se;
        //cout << a[u][v] << endl;
        if(a[u][v] > res.fi){
            res = mp(a[u][v], i);
        }
    }

    cout << res.se << " " << res.fi - 1;

}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
