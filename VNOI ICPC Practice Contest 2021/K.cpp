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
        cin >> a[i].fi >> a[i].se;
        Ox.pb(a[i].fi);
        Oy.pb(a[i].se);
    }
    sort(Ox.begin(), Ox.end());
    sort(Oy.begin(), Oy.end());
    int res = INF;
    for(int dx = -5; dx <= 5; dx++){
        for(int dy = -5; dy <= 5; dy++){
            int mid = n / 2;
            int pos1 = min(n - 1, max(0LL, mid + dx));
            int pos2 = min(n - 1, max(0LL, mid + dy));
            int u = Ox[pos1];
            int v = Oy[pos2];
            int sum = 0;
            for(int i = 1; i <= n; i++){
                int x = abs(u - a[i].fi);
                int y = abs(v - a[i].se);
                sum += max(x, y);
            }
            res = min(res, sum);
        }
    }
    cout << res;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
