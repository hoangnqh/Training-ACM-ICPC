#include<bits/stdc++.h>
using namespace std;

//#define int long long

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ld long double

typedef pair<int, int> II;
typedef pair<int, II> III;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n;
int a[1005][1005];
II dp[1005][1005];
vector<vector<vector<int> > > val(6);

int getVal(int x, int y){
    if(x == 0) return 1;
    int val = 0;
    while(x % y == 0){
        val += 1;
        x /= y;
    }
    return val;
}

II sum(II a, II b){
    return mp(a.fi + b.fi, a.se + b.se);
}

II Min(II a, II b, int key){
    if(key){
        if(a.fi == b.fi){
            if(a.se < b.se) return a;
            else return b;
        }
        if(a.fi < b.fi) return a;
        else return b;
    }
    else{
        if(a.se == b.se){
            if(a.se < b.se) return a;
            else return b;
        }
        if(a.se < b.se) return a;
        else return b;
    }
}
vector<char> trace[2];
int cal(int key){
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(a[i][j] == 0){
                dp[i][j] = mp(INF, INF);
            }
            else{
                if(i == 1 && j == 1){
                    dp[i][j] = mp(val[2][i][j], val[5][i][j]);
                    continue;
                }
                if(i == 1){
                    dp[i][j] = sum(dp[i][j - 1], mp(val[2][i][j], val[5][i][j]));
                    continue;
                }
                if(j == 1){
                    dp[i][j] = sum(dp[i - 1][j], mp(val[2][i][j], val[5][i][j]));
                    continue;
                }
                dp[i][j] = Min(sum(dp[i][j - 1], mp(val[2][i][j], val[5][i][j])), sum(dp[i - 1][j], mp(val[2][i][j], val[5][i][j])), key);
            }
        }
    }

    int u = n, v = n;
    while(trace[key].size() != n + n - 2){
        if(u == 1){
            trace[key].pb('R');
            v -= 1;
            continue;
        }
        if(v == 1){
            trace[key].pb('D');
            u -= 1;
            continue;
        }
        if(sum(dp[u - 1][v], mp(val[2][u][v], val[5][u][v])) == dp[u][v]){
            trace[key].pb('D');
            u -= 1;
        }
        else{
            trace[key].pb('R');
            v -= 1;
        }
    }
    return min(dp[n][n].fi, dp[n][n].se);
}

void solve(){
    cin >> n;
    val[2] = vector<vector<int> > (n + 5, vector<int> (n + 5, 0));
    val[5] = vector<vector<int> > (n + 5, vector<int> (n + 5, 0));
    int Min = INF;
    II pos = {1, 1};
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            cin >> a[i][j];
            val[2][i][j] = getVal(a[i][j], 2);
            val[5][i][j] = getVal(a[i][j], 5);
            if(a[i][j] == 0){
                Min = 0;
                pos = mp(i, j);
            }
        }
    }
    int val1 = cal(0);
    int val2 = cal(1);

    if(Min == 0 && min(val1, val2) > 1){
        cout << 1 << '\n';
        for(int i = 2; i <= pos.fi; i++){
            cout << 'D';
        }
        for(int j = 2; j <= pos.se; j++){
            cout << 'R';
        }
        for(int i = pos.fi + 1; i <= n; i++){
            cout << 'D';
        }
        for(int j = pos.se + 1; j <= n; j++){
            cout << 'R';
        }
        return;
    }
    if(val1 < val2){
        cout << val1 << '\n';
        for(int i = trace[0].size() - 1; i >= 0; i--){
            cout << trace[0][i];
        }

    }
    else{
        cout << val2 << '\n';
        for(int i = trace[1].size() - 1; i >= 0; i--){
            cout << trace[1][i];
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
/*
2
4 10
25 3
*/
