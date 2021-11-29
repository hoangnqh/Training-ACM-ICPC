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
const int N = 1e2 + 5;

int n, q;
int f[1000006];
int a[N];

void solve(){
    cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    for(int i = 1; i <= 1000000; i++){
        f[i] = INF;
    }

    for(int i = 1; i <= n; i++){
        f[i] = a[i];
    }

    for(int i = n + 1; i <= 1000000; i++){
        for(int j = 1; j <= n; j++){
            if(f[i - j] != INF){
                f[i] = min(f[i], f[i - j] + a[j]);
            }
        }
    }
    int mx = 1e6;
    for(int i = 1; i <= q; i++){
        int x;
        cin >> x;
        if(x <= n){
            cout << a[x] << '\n';
            continue;
        }
        int ans = INF;
        for(int pos = 1; pos <= n; pos++){
            int temp = x;
            int res = 0;
            if(temp > mx){
                int cl = temp - mx;
                int t = (cl - 1) / pos + 1;
                res += t * a[pos];
                temp -= t * pos;
            }
            res += f[temp];
            ans = min(ans, res);
        }
        cout << ans << '\n';
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}

