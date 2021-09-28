#include <bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define mp make_pair
#define pb push_back

#define int int64_t

typedef pair<int, int> II;
typedef pair<int, II> III;
typedef pair<II, II> IIII;

const int INF = 1e9;
const long double PI = 3.1415926535898;
const int N = 300000 + 5;

int p[N];
vector<IIII> e;
int mark[N];

int t, n, m;
vector<II> a[N];
int h[N], heap[N], pos[N], vt[N], par[N], ts[N], col[N], nchild[N];
int Time = 0, cnt = 0;

int st[4 * N];

void DFS(int u)
{
    nchild[u] = 1;
    for(int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i].se;
        int w = a[u][i].fi;
        if(v == par[u]) continue;
        par[v] = u;
        ts[v] = w;
        DFS(v);
        nchild[u] += nchild[v];
    }
}
void HLD(int u)
{
    if(heap[cnt] == 0) heap[cnt] = u;
    col[u] = cnt;
    pos[u] = ++Time;
    vt[Time] = u;
    int hv = -1;
    for(int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i].se;
        if(v == par[u]) continue;
        if(hv == -1 || nchild[hv] < nchild[v]) hv = v;
    }
    if(hv != -1) HLD(hv);
    for(int i = 0; i < a[u].size(); i++)
    {
        int v = a[u][i].se;
        if(v == par[u] || v == hv) continue;
        cnt += 1;
        h[cnt] = h[col[u]] + 1;
        HLD(v);
    }
}

void build(int id, int l, int r)
{
    if(l == r){
        st[id] = ts[vt[l]];
        return;
    }
    int m = (l + r) / 2;
    build(id * 2, l, m);
    build(id * 2 + 1, m + 1, r);
    st[id] = max(st[id * 2], st[id * 2 + 1]);
}

int query(int id, int l, int r, int u, int v)
{
    if(l > v || u > r) return -INF;
    if(u <= l && r <= v) return st[id];

    int m = (l + r ) / 2;
    int ansl = query(id * 2, l, m, u, v);
    int ansr = query(id * 2 + 1, m + 1, r, u, v);

    return max(ansl, ansr);
}

int QUERY(int u, int v)
{
    if(u == v) return 0;
    int ans = -INF;
    while(col[u] != col[v])
    {
        if(h[col[u]] > h[col[v]])
        {
            int p = heap[col[u]];
            int l = pos[p], r = pos[u];
            ans = max(ans, query(1, 1, n, l, r));
            u = par[p];
        }
        else
        {
            int p = heap[col[v]];
            int l = pos[p], r = pos[v];
            ans = max(ans, query(1, 1, n, l, r));
            v = par[p];
        }
    }
    if(pos[v] < pos[u]) swap(u, v);
    ans = max(ans, query(1, 1, n, pos[u] + 1, pos[v]));
    return ans;
}

int finds(int u){
    return (p[u] < 0 ? u : p[u] = finds(p[u]));
}

int join(int u, int v){
    u = finds(u);
    v = finds(v);
    if(u == v) return 0;
    if(p[u] > p[v]) swap(u, v);
    p[u] += p[v];
    p[v] = u;
    return 1;
}

void initialize()
{
    for(int i = 1; i <= n; i++)
        a[i].clear();
    e.clear();
    for(int i = 1; i < 4 * n; i++)
        st[i] = -INF;
    for(int i = 1; i <= n; i++){
        p[i] = -1;
    }
    for(int i = 1; i <= m; i++){
        mark[i] = 0;
    }
    for(int i = 0; i <= n; i++)
    {
        heap[i] = 0;
        h[i] = 0;
        pos[i] = 0;
        vt[i] = 0;
        par[i] = 0;
        ts[i] = -INF;
        col[i] = 0;
        nchild[i] = 0;
    }
    Time = 0, cnt = 0;
}

void solve()
{
    cin >> n >> m;
    initialize();
    for(int i = 1; i <= m; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        e.pb(mp(mp(w, i), mp(u, v)));
    }
    sort(e.begin(), e.end());
    int cnt = 0;
    for(auto it: e){
        int w = it.fi.fi, i = it.fi.se, u = it.se.fi, v = it.se.se;
        if(join(u, v)){
            mark[i] = 1;
            a[u].pb(mp(w, v));
            a[v].pb(mp(w, u));
            cnt += 1;
            //cout << u << " " << v << endl;
        }
    }
    if(cnt != n - 1){
        cout << -1 << '\n';
        return;
    }
    DFS(1);
    HLD(1);
    build(1, 1, n);

    vector<int> res;
    for(auto it: e){
        int w = it.fi.fi, i = it.fi.se, u = it.se.fi, v = it.se.se;
        if(mark[i]) continue;
        int val = QUERY(u, v);
        if(val == w){
            res.push_back(i);
        }
    }
    sort(res.begin(), res.end());
    cout << res.size() << " ";
    for(int i: res) cout << i << " ";
    cout << '\n';

}

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);
    cin >> t;
    for(int i = 1; i <= t; i++)
        solve();
}

/**

*/
