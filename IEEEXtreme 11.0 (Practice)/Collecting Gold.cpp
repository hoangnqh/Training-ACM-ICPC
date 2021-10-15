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

int n, m;
int id[N];
int s = 1, t = 1;
int vs = INF, vt = -INF;
vector<II> a[N];
map<int, int> Map;
II d[N];
int cnt[N];

vector<int> nt = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47}; // 15

struct node{
	int x, y, z;
	node(){}
	node(int x, int y, int z){
		this->x = x; this->y = y; this->z = z;
	}
};

struct compare{
	bool operator() (const node a, const node b) const{
		if(a.x != b.x) return a.x < b.x;
		else{
			if(a.y != b.y) return a.y > b.y;
			else{
				return a.z < b.z;
			}
		}
	}
};

int val(int x){
    int val = 1;
    int res = 0;
    for(int i = 0; i < nt.size(); i++){
        val = val * nt[i];
        if(val > x) break;
        res = i + 1;
    }
    return res;
}

void solve(){
    cin >> n >> m;
    int s = 1, t = 1;
    for(int i = 1; i <= n; i++){
        cin >> id[i];
        cnt[i] = val(id[i]);
        Map[id[i]] = i;
        if(vs > id[i]){
            vs = id[i];
            s = i;
        }
        if(vt < id[i]){
            vt = id[i];
            t = i;
        }
    }
    for(int i = 1; i <= m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        u = Map[u];
        v = Map[v];
        a[u].pb(mp(w, v));
        a[v].pb(mp(w, u));
    }

    priority_queue<node, vector<node>, compare> heap;
    for(int i = 1; i <= n; i++){
        d[i] = mp(INF, cnt[s]);
    }
    d[s] = mp(0, cnt[s]);

    heap.push(node(0, cnt[s], s));
    while(heap.size()){
        int du = heap.top().x;
        int u = heap.top().z;
        int ts = heap.top().y;
        heap.pop();
        for(int i = 0; i < a[u].size(); i++){
            int v = a[u][i].se;
            int uv = a[u][i].fi;
            if(du + uv == d[v].fi){
                if(ts + cnt[v] > d[v].se){
                    d[v].se = ts + cnt[v];
                    heap.push(node(d[v].fi, d[v].se, v));
                }
            }
            if(du + uv < d[v].fi){
                d[v].fi = du + uv;
                d[v].se = ts + cnt[v];
                heap.push(node(d[v].fi, d[v].se, v));
            }
        }
    }
    cout << d[t].se;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
/*
30m, 1 submit
*/
