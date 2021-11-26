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
const int N = 1e6 + 5;

int n;
II a[N];

void solve(){
    cin >> n;
    vector<int> Ox, Oy;
    for(int i = 1; i <= n; i++){
        int u, v, x, y;
        cin >> u >> v;
        x = u + v;
        y = (1000000 - u) + v;
        Ox.pb(x);
        Oy.pb(y);
    }
    sort(Ox.begin(), Ox.end());
    sort(Oy.begin(), Oy.end());
    int res = INF;
    for(int x = Ox[n / 2] - 3; x <= Ox[n / 2] + 3; x++){
        for(int y = Oy[n / 2] - 3; y <= Oy[n / 2] + 3; y++){
            if((x + y) % 2 == 1) continue;
            int sum = 0;
            for(int u: Ox) sum += abs(x - u);
            for(int v: Oy) sum += abs(y - v);
            res = min(res, sum);
        }
    }
    cout << res / 2;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
/*
3
0 0
0 1
1 1
*/
