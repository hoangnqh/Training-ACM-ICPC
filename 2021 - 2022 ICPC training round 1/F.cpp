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

int n, h;

int dp[100][100];

int ql(int n, int h){
    if(n == 1){
        if(h == 1) return 1;
        else return 0;
    }
    if(h <= 1) return 0;
    if(dp[n][h] != -1) return dp[n][h];
    int res = 0;
    res += 2 * ql(n - 1, h - 1);
    for(int i = 1; i < n - 1; i++){
        for(int j = 1; j <= h - 1; j++){
            res += ql(i, j) * ql(n - i - 1, h - 1);
            if(j != h - 1)
            res += ql(i, h - 1) * ql(n - i - 1, j);
        }
    }
    return dp[n][h] = res;
}

void solve(){
    cin >> n >> h;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            dp[i][j] = -1;
        }
    }
    int res = 0;
    for(int i = h; i <= n; i++){
        res += ql(n, i);
    }
    cout << res;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
