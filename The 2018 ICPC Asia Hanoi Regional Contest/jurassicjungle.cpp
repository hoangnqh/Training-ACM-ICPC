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

int n, m;

void solve(){
    // Cycle
    if(n == m){
        cout << "YES" << '\n';
        for(int i = 1; i < n; i++){
            cout << i << " " << i + 1 << '\n';
        }
        cout << n << " " << 1 << '\n';
        return;
    }

    // Full graph
    if((n * (n - 1)) / 2 == m){
        cout << "YES" << '\n';
        for(int i = 1; i <= n; i++){
            for(int j = i + 1; j <= n; j++){
                cout << i << " " << j << '\n';
            }
        }
        return;
    }

    // Full bipartite graph
    if(n % 2 == 0 && (n / 2) * (n / 2) == m){
        cout << "YES" << '\n';
        for(int i = 1; i <= n / 2; i++){
            for(int j = n / 2 + 1; j <= n; j++){
                cout << i << " " << j << '\n';
            }
        }
        return;
    }

    cout << "NO" << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    while(1){
        cin >> n >> m;
        if(n == -1){
            return 0;
        }
        solve();
    }
}
