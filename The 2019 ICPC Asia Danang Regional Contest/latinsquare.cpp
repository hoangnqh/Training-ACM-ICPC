#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

typedef pair<int, int> II;

const int INF = 1e9;
const int N = 205;

int n, k;
int res[N][N];

int d[N];
int s, t;
int trace[N];

struct Edge{
    int u, v, cap, flow;
    Edge() {}
    Edge(int u, int v, int cap, int flow = 0) : u(u), v(v), cap(cap), flow(flow) {}
};

vector<int> a[N];
vector<Edge> e;

void addEdge(int u, int v, int cap)
{
    a[u].pb(e.size()); e.pb(Edge(u, v, cap, 0));
    a[v].pb(e.size()); e.pb(Edge(v, u, 0, 0));
}

bool bfs(){
    for(int i = 1; i <= 2 * n + 2; i++)
        d[i] = 0;
    queue<int> q;
    q.push(s);
    d[s] = 1;
    while(q.size() && !d[t]){
        int u = q.front();
        q.pop();
        for(int i: a[u]){
            int v = e[i].v;
            if(e[i].cap - e[i].flow <= 0) continue;
            if(d[v]) continue;
            d[v] = 1;
            trace[v] = i;
            q.push(v);
        }
    }
    return d[t];
}

void fordFulkerson(int x){
    int maxFlow = 0;
    while(bfs()){
        int mincap = INF;
        for(int v = t; v != s; v = e[trace[v]].u){
            int i = trace[v];
            mincap = min(mincap, e[i].cap - e[i].flow);
        }

        maxFlow += mincap;
        for(int v = t; v != s; v = e[trace[v]].u){
            int i = trace[v];
            e[i].flow += mincap;
            e[i ^ 1].flow -= mincap;
        }
    }

    for(auto it: e){
        int u = it.u, v = it.v, flow = it.flow;
        if(flow > 0 && u <= n){
            res[u][v - n] = x;
        }
    }
}

void build(){
    e.clear();
    for(int i = 1; i <= 2 * n + 2; i++){
        a[i].clear();
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(res[i][j] == 0){
                addEdge(i, j + n, 1);
            }
        }
    }
    for(int i = 1; i <= n; i++){
        addEdge(s, i, 1);
    }
    for(int i = n + 1; i <= 2 * n; i++){
        addEdge(i, t, 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> n >> k;
    set<int> Set;
    for(int i = 1; i <= n; i++) Set.insert(i);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> res[i][j];
            Set.erase(res[i][j]);
        }
    }

    s = 2 * n + 1, t = 2 * n + 2;

    for(int i: Set){
        build();
        fordFulkerson(i);
    }

    cout << "YES" << '\n';
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cout << res[i][j] << " ";
        }
        cout << endl;
    }
}
