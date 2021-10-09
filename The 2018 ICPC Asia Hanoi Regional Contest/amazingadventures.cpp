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

struct MincostFlow{
    struct Edge{
        int u, v, cost, cap, flow;
        Edge() {}
        Edge(int u, int v, int cost, int cap, int flow): u(u), v(v), cost(cost), cap(cap), flow(flow){}
    };

    int n, k;
    vector<int> mark, trace, d, cnt;
    vector<vector<int> > a;
    vector<Edge> e;

    MincostFlow() {}

    MincostFlow(int n, int k): n(n), k(k), d(n + 5), trace(n + 5), mark(n + 5), a(n + 5), cnt(n + 5){}

    void addEdge(int u, int v, int cost, int cap){
        a[u].pb(e.size()); e.pb(Edge(u, v, cost, cap, 0));
        a[v].pb(e.size()); e.pb(Edge(v, u, -cost, 0, 0));
    }

    bool bellmanFord(int s, int t){
        for(int i = 1; i <= n; i++){
            trace[i] = -1;
            d[i] =  INF;
            mark[i] =  false;
            cnt[i] = 0;
        }
        queue<int> q;
        q.push(s);
        d[s] = 0;
        mark[s] = true;

        while(q.size()){
            int u = q.front();
            q.pop();
            mark[u] = false;
            for(auto i: a[u]){
                if(e[i].cap - e[i].flow <= 0) continue;
                int v = e[i].v;
                if(d[v] > d[u] + e[i].cost){
                    d[v] = d[u] + e[i].cost;
                    trace[v] = i;
                    if(!mark[v]){
                        q.push(v);
                        mark[v] = true;

                        cnt[v] += 1;
                        if(cnt[v] > n){
                            return false;  /// Negative cycle
                        }
                    }
                }
            }
        }
        return d[t] < INF;
    }

    II edmondsKarp(int s, int t)
    {
        int resFlow = 0, resCost = 0;
        while(bellmanFord(s, t)){
            int ans = INF;
            for(int v = t; v != s; v = e[trace[v]].u){
                ans = min(ans, e[trace[v]].cap - e[trace[v]].flow);
            }
            for(int v = t; v != s; v = e[trace[v]].u){
                e[trace[v]].flow += ans;
                e[trace[v] ^ 1].flow -= ans;
            }
            resFlow += ans;
            resCost += d[t];

        }
        ///{maxFlow, minCost}
        return {resFlow, resCost};
    }

    void minCost(int s, int t, int B, int G, int row, int col){
        II res = edmondsKarp(s, t);

        if(res.first < k){
            cout << "NO" << '\n';
            return;
        }

        cout << "YES" << '\n';

        queue<int> q[n + 5];
        vector<int> ans[3];
        for(int i = 0; i < e.size(); i++){
            if(i % 2 == 0 && e[i].flow > 0){
                q[e[i].u].push(e[i].v);
            }
        }


        for(int i = 1; i <= k; i++){
            int v = s;
            while(v != t){
                if(v <= (n - 1) / 2) ans[i].pb(v);
                int u = q[v].front();
                q[v].pop();
                v = u;
            }
        }

        vector<int> tv;

        if(ans[1].back() == B){
            for(int i = ans[1].size() - 1; i >= 0; i--) tv.pb(ans[1][i]);
            for(int i = 1; i < ans[2].size(); i++) tv.pb(ans[2][i]);
        }
        else{
            for(int i = ans[2].size() - 1; i >= 0; i--) tv.pb(ans[2][i]);
            for(int i = 1; i < ans[1].size(); i++) tv.pb(ans[1][i]);
        }

        for(int i = 1; i < tv.size(); i++){
            int u = (tv[i] - 1) / col;
            int v = tv[i] - u * col;
            int u1 = (tv[i - 1] - 1) / col;
            int v1 = tv[i - 1] - u1 * col;
            if(u > u1){
                cout << "U";
            }
            if(u1 > u){
                cout << "D";
            }
            if(v > v1){
                cout << "R";
            }
            if(v1 > v){
                cout << "L";
            }
        }
        cout << '\n';

    }
};

int row, col;
int x[4];

void solve(){
    for(int i = 0; i < 4; i++){
        int u, v;
        cin >> u >> v;
        x[i] = col * (u - 1) + v;
    }
    int n = row * col;

    MincostFlow g(2 * n + 1, 2);

    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            int u1 = col * (i - 1) + j;
            int u2 = u1 + n;
            if(u1 == x[1]) continue;
            g.addEdge(u1, u2, 0, 1);

        }
    }
    int s = x[1], t = 2 * n + 1;
    g.addEdge(x[0] + n, t, 0, 1);
    g.addEdge(x[2] + n, t, 0, 1);

    for(int i = 1; i <= row; i++){
        for(int j = 1; j <= col; j++){
            int u = col * (i - 1) + j;
            if(u == x[3] || u == x[0] || u == x[2]) continue;
            for(int t = 0; t < 4; t++){
                int u1 = i + dx[t];
                int v1 = j + dy[t];
                if(u1 < 1 || u1 > row || v1 < 1 || v1 > col) continue;
                int v = col * (u1 - 1) + v1;
                if(v == x[3] || v == x[1]) continue;
                if(u == x[1]){
                    g.addEdge(u, v, 1, 1);
                }
                else{
                    g.addEdge(u + n, v, 1, 1);
                }
            }
        }
    }
    g.minCost(s, t, x[0], x[2], row, col);

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    while(1){
        cin >> row >> col;
        if(row == 0) return 0;
        solve();
    }
}
