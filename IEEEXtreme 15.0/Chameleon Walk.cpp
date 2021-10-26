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
const int N = 2e4 + 5;

vector<vector<III> > a;
int n, m, k;
int d[5][N];

int dijkstra_relaxing(int col){
    for(int i = 1; i <= n; i++){
        d[col][i] = INF;
    }
    d[col][1] = 0;
    priority_queue<III, vector<III>, greater<III> > heap;
    heap.push(mp(0, mp(col, 1)));
    while(heap.size()){
        int du = heap.top().fi;
        int c = heap.top().se.fi;
        int u = heap.top().se.se;
        heap.pop();

        for(int i = 0; i < a[u].size(); i++){
            int w = a[u][i].fi;
            int mau = a[u][i].se.fi;
            int v = a[u][i].se.se;
            if(mau != c) continue;
            if(d[col][v] > du + w){
                d[col][v] = du + w;
                heap.push(mp(d[col][v], mp(col, v)));
            }
        }
    }
    return d[col][n];
}

int dijkstra(int C){
    for(int c = 0; c < 5; c++){
        for(int i = 1; i <= n; i++){
            d[c][i] = INF;
        }
    }

    priority_queue<III, vector<III>, greater<III> > heap;

    d[0][1] = 0;
    heap.push(mp(0, mp(0, 1)));

    while(heap.size()){
        int du = heap.top().fi;
        int c = heap.top().se.fi;
        int u = heap.top().se.se;
        heap.pop();

        for(int i = 0; i < a[u].size(); i++){
            int w = a[u][i].fi;
            int mau = a[u][i].se.fi;
            int v = a[u][i].se.se;
            if(mau != c) w += C;
            if(d[mau][v] > du + w){
                d[mau][v] = du + w;
                heap.push(mp(d[mau][v], mp(mau, v)));
            }
        }
    }
    int ans = INF;
    for(int c = 0; c < 5; c++){
        ans = min(ans, d[c][n]);
    }
    return ans;
}


void solve(){
    cin >> n >> m >> k;
    a.clear();
    a = vector<vector<III> > (n + 5);
    for(int i = 1; i <= m; i++){
        int u, v, w;
        char c;
        cin >> u >> v >> w >> c;
        int col = c - 'a';
        a[u].pb(mp(w, mp(col, v)));
        a[v].pb(mp(w, mp(col, u)));
    }

    int VAL = dijkstra_relaxing(0);
    if(VAL <= k){
        cout << "relaxing" << '\n';
        return;
    }

    int ans = -1;
    int l = 1, r = k;
    while(l <= r){
        int m = (l + r) / 2;
        int val = dijkstra(m);
        if(val <= k){
            ans = m;
            l = m + 1;
        }
        else r = m - 1;
    }

    if(ans == -1){
        cout << "impossible" << '\n';
        return;
    }
    else{
        cout << ans << '\n';
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T; while(T--)
    solve();
}
