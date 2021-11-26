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
vector<int> res;
int d[N];

void dfs(int u){
    d[u] = 1;
    if(d[(u * 2) % n] == 0){
        dfs((u * 2) % n);
    }
    if(d[(u * 2 + 1) % n] == 0){
        dfs((u * 2 + 1) % n);
    }
    res.pb(u);
}

void solve(){
    cin >> n;
    if(n % 2 == 1){
        cout << -1;
        return;
    }
    dfs(0);
    reverse(res.begin(), res.end());
    for(int i: res) cout << i << " ";
    cout << 0;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
