#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define int int64_t

typedef pair<int, int> II;
typedef pair<int, II> III;

const int INF = 1e15;
const int N = 5e5 + 5;

int n, m;
int h1, s1, h2, s2;
vector<II> a[N];
int d[4][N];
vector<III> e;

void dijkstra(int x){
    priority_queue<II, vector<II>, greater<II> > heap;
    for(int i = 1; i <= n; i++){
        d[x][i] = INF;
    }
    if(x == 0){
        d[x][h1] = 0;
        heap.push(mp(0, h1));
    }
    if(x == 1){
        d[x][s1] = 0;
        heap.push(mp(0, s1));
    }
    if(x == 2){
        d[x][h2] = 0;
        heap.push(mp(0, h2));
    }
    if(x == 3){
        d[x][s2] = 0;
        heap.push(mp(0, s2));
    }

    while(heap.size()){
        int u = heap.top().se;
        int du = heap.top().fi;
        heap.pop();
        for(int i = 0; i < a[u].size(); i++){
            int v = a[u][i].se;
            int w = a[u][i].fi;
            if(du + w < d[x][v]){
                d[x][v] = du + w;
                heap.push(mp(d[x][v], v));
            }
        }
    }
}

int checkEdge(int u, int v, int uv, int x){
    if(x == 0){
        if(d[x][u] + uv + d[x + 1][v] == d[x][s1]) return 1;
        else return 0;
    }
    else{
        if(d[x][u] + uv + d[x + 1][v] == d[x][s2]) return 1;
        else return 0;
    }
}

int checkVertex(int u, int x){
    if(x == 0){
        if(d[x][u] + d[x + 1][u] == d[x][s1]) return 1;
        else return 0;
    }
    else{
        if(d[x][u] + d[x + 1][u] == d[x][s2]) return 1;
        else return 0;
    }
}

void solve(){
    //Initialize
    for(int i = 1; i <= n; i++){
        a[i].clear();
    }
    e.clear();

    cin >> h1 >> s1 >> h2 >> s2;
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        a[u].pb(mp(w, v));
        a[v].pb(mp(w, u));
        e.pb(mp(w, mp(u, v)));
        e.pb(mp(w, mp(v, u)));
    }

    for(int i = 0; i < 4; i++){
        dijkstra(i);
    }

    int res = 0;

    // Check vertex
    for(int i = 1; i <= n; i++){
        if(d[0][i] == d[2][i] && checkVertex(i, 0) && checkVertex(i, 2)){
            res += 1;
        }
    }

    // Check edge
    for(auto it: e){
        int w = it.fi, u = it.se.fi, v = it.se.se;
        if(abs(d[0][u] - d[2][v]) < w && checkEdge(u, v, w, 0) && checkEdge(v, u, w, 2)){
            res += 1;
        }

        //r > 1e9
        if(d[0][u] == d[2][u] && checkEdge(u, v, w, 0) && checkEdge(u, v, w, 2)){
            cout << -1 << '\n';
            return;
        }
    }

    // Check root
    if(s1 == s2){
        if(d[0][s1] != d[2][s2]) res += 1;
    }
    else{
        if(d[0][s1] < d[2][s1] && checkVertex(s1, 2)){
            res += 1;
        }
        if(d[2][s2] < d[0][s2] && checkVertex(s2, 0)){
            res += 1;
        }
    }

    cout << res << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    while(cin >> n >> m){
        if(n == 0) break;
        else solve();
    }
}
/*
4 3
1 2 3 4
1 2 3
2 3 2
2 4 5
0 0
*/
