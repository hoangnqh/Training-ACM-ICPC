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
int a[N];
int x[N];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    int cnt = 0;
    for(int i = 0; i <= 100000; i++){
        x[i] = 0;
    }
    for(int i = 1; i <= n; i++){
        x[a[i]] += 1;
    }

    vector<int> temp, temp1, temp2;

    int pos = 1;
    while(a[pos] == 0 && pos <= n){
        temp1.pb(a[pos]);
        pos += 1;
    }
    while(pos <= n){
        while(pos <= n && x[a[pos]] > 2){
            temp1.pb(a[pos]);
            x[a[pos]] -= 1;
            pos += 1;
        }
        temp1.pb(a[pos]);
        x[a[pos]] -= 1;
        pos += 1;
        if(pos <= n){
            if(x[a[pos]] >= 2) continue;
            temp2.pb(a[pos]);
            x[a[pos]] -= 1;
            pos += 1;
        }
    }
    int res = 0;
    for(int i: temp1) temp.pb(i);
    for(int i = temp2.size() - 1; i >= 0; i--) temp.pb(temp2[i]);
    for(int i = 0; i < temp.size() - 1; i++){
        res += temp[i] * temp[i + 1];
    }

    cout << res << '\n';
    for(int i: temp) cout << i << " ";
    cout << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T; while(T--)
    solve();
}
