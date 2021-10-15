#include <bits/stdc++.h>
using namespace std;

struct Edge
{
    int u, v, cap, flow;
};

struct Dinic
{
    int n, s, t;
    vector<vector<int> > a;
    vector<int> d, cur;
    vector<Edge> e;

    Dinic() {};

    Dinic(int _n, int _s, int _t)
    {
        n = _n;
        s = _s;
        t = _t;
        a = vector<vector<int> > (n + 5);
        d = cur = vector<int> (n + 5);
    }

    void addEdge(int u, int v, int cap)
    {
        Edge e1 = {u, v, cap, 0ll};
        Edge e2 = {v, u, 0ll, 0ll};
        a[u].push_back(e.size()); e.push_back(e1);
        a[v].push_back(e.size()); e.push_back(e2);
    }

    bool bfs()
    {
        for(int i = 1; i <= n; i++)
        {
            d[i] = -1;
        }
        d[s] = 0;
        queue<int> q;
        q.push(s);
        while(q.size())
        {
            int u = q.front();
            q.pop();
            for(int i = 0; i < a[u].size(); i++)
            {
                int id = a[u][i];
                int v = e[id].v;
                if(e[id].cap > e[id].flow && d[v] < 0)
                {
                    d[v] = d[u] + 1;
                    q.push(v);
                }
            }
        }
        return d[t] > 0;
    }

    int dfs(int u, int val)
    {
        if(val == 0ll) return val;
        if(u == t) return val;
        for(; cur[u] < a[u].size(); cur[u]++)
        {
            int id = a[u][cur[u]];
            int v = e[id].v;
            if(d[v] != d[u] + 1) continue;
            int ans = dfs(v, min(val, e[id].cap - e[id].flow));
            if(ans)
            {
                e[id].flow += ans;
                e[id ^ 1].flow -= ans;
                return ans;
            }
        }
        return 0;
    }

    void Answer()
    {
        int maxFlow = 0;
        while(bfs())
        {
            for(int i = 1; i <= n; i++)
                cur[i] = 0;
            while(1)
            {
                int ans = dfs(s, (1 << 30));
                if(!ans) break;
                maxFlow += ans;
            }
        }
        int val = (n - 2) / 2;
        cout << val - maxFlow << '\n';
    }
};

int n;
int dd[205];

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0);

    cin >> n;
    int S = 2 * n + 1, T = 2 * n + 2;
    Dinic g(2 * n + 2, S, T);
    for(int i = 1; i <= n; i++){
        g.addEdge(S, i, 1);
        g.addEdge(i + n, T, 1);
    }
    string s;
    cin.ignore();
    for(int i = 0; i < n; i++){
        getline(cin, s);
        s.push_back(' ');
        for(int j = 0; j < n; j++){
            dd[j] = 0;
        }
        int cnt = 0;
        for(int j = 0; j < s.size(); j++){
            if(s[j] == ' '){
                dd[cnt] = 1;
                cnt = 0;
            }
            else cnt = cnt * 10 + (s[j] - '0');
        }
        for(int j = 0; j < n; j++){
            if(j == i) continue;
            if(dd[j]) continue;
            g.addEdge(i + 1, j + 1 + n, 1);
            //cout << i + 1 << " " << j + 1 << '\n';
        }
    }
    g.Answer();
}
