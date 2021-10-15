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
const int N = 1e5 + 5;

int n;
int col[N];
int par[N];
vector<int> a[10005];

int finds(int u){
    return par[u] < 0 ? u : par[u] = finds(par[u]);
}

int join(int U, int V){
    int u = finds(U);
    int v = finds(V);
    if(u == v) return 0;
    if(par[u] > par[v]) swap(u, v);
    par[u] += par[v];
    par[v] = u;

    if(col[u] == -1) col[u] = 1;

    if(col[v] == -1){
        if(v == V){
            col[v] = col[U] ^ 1;
        }
        else col[v] = col[V] ^ 1;
        return 1;
    }

    if(col[U] != col[V]){
        return 1;
    }

    // col[v] == col[u]
    set<int> s;
    queue<int> q;
    s.insert(v);
    q.push(v);
    while(q.size()){
        int x = q.front();
        q.pop();
        col[x] = col[x] ^ 1;
        for(int y: a[x]){
            if(s.count(y)) continue;
            s.insert(y);
            q.push(y);
        }
    }
    return 1;
}

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        col[i] = -1;
        par[i] = -1;
    }
    int u, v;
    cin >> u >> v;
    a[u].pb(v);
    a[v].pb(u);
    join(u, v);
    while(1){
        cout << 1 << '\n';
        cout.flush();
        cin >> u >> v;
        if(join(u, v) == 0){
            if(col[u] == col[v]){
                cout << 0 << '\n';
                cout.flush();
                return;
            }
        }
        a[u].pb(v);
        a[v].pb(u);
    }

}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
