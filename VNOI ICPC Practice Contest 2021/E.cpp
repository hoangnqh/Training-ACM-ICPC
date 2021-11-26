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

int n, x;
int a[10];
vector<int> f(1000005, 0);

void solve(){
    cin >> x;
    cin >> n;
    set<int> s;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        s.insert(a[i]);
    }
    n = 0;
    for(int it: s){
        n += 1;
        a[n] = it;
    }
    f[0] = 1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= x; j++){
            if(j >= a[i] && f[j - a[i]] != 0){
                f[j] += f[j - a[i]];
            }
        }
    }
    cout << f[x];

}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
