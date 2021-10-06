#include<bits/stdc++.h>
using namespace std;

#define int long long

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ld long double
#define cc cout<<"CC"<<endl;

typedef pair<int, int> II;
typedef pair<int, II> III;

/// 4 directions
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

/// Default long long max => 1e18
const int INF = 1e18;

/// Default MOD => 1e9 + 7
const int MOD = 1e9 + 7;

/// Input limit
const int N = 1e5 + 5;

int r, c, n;
int a[105][105];
queue<II> q, temp;

void solve(){
    cin >> r >> c >> n;
    for(int i = 1; i <= n; i++){
        int u, v;
        cin >> u >> v;
        if(a[u][v] == 0){
            q.push(mp(u, v));
        }
        a[u][v] = 1;
    }
    int res = 1;
    while(q.size() || temp.size()){
        if(q.size() == 0 && temp.size()){
            res += 1;
            q = temp;
            while(temp.size()) temp.pop();
        }
        int u = q.front().fi;
        int v = q.front().se;
        q.pop();
        for(int i = 0; i < 4; i++){
            int x = u + dx[i];
            int y = v + dy[i];
            if(x < 1 || x > r || y < 1 || y > c) continue;
            if(a[x][y]) continue;
            temp.push(mp(x, y));
            a[x][y] = 1;
        }
    }

    cout << res;
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T = 1;
	//cin >> T;
	while(T--){solve();}
}
