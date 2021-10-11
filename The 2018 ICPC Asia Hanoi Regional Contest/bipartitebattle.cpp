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

int POW(int a, int b){
    if(b == 0) return 1;
    if(b == 1) return a;
    int c = POW(a, b / 2);
    c = (c * c) % MOD;
    if(b & 1) c = (c * a) % MOD;
    return c;
}

void solve(){
    cin >> n;
    int node = 0;
    int edge = 0;
    int res = 1;
    for(int i = 1; i <= n; i++){
        int a, b;
        cin >> a >> b;
        node += a + b;
        edge = a * b;
        if(i < n){
            res = (res * POW(2, edge)) % MOD;
        }
        else{
            // (res * POW(2, edge - 1)) / 2
            res = (res * POW(2, edge - 1)) % MOD;
        }
    }
    if(node % 2){
        cout << 0 << '\n';
        return;
    }
    else{
        cout << res;
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
