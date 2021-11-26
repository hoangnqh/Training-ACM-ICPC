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

int d[1000];
int dp[2605][2605];
int mark[2605];

void solve(){
    string s, s2;
    cin >> s;
    int n = s.size();
    s = '@' + s;
    if(s.size() > 2600){
        for(int i = 1; i <= n; i++){
            d[s[i]] += 1;
            if(d[s[i]] >= 100){
                for(int j = 1; j <= 100; j++){
                    cout << s[i];
                }
                return;
            }
        }
    }

    s2 = "@";
    for(int i = n; i >= 1; i--){
        s2.pb(s[i]);
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if(s[i] == s2[j]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    vector<char> res;
    int u = n, v = n;
    while(u >= 1 && v >= 1){
        if(s[u] == s2[v]){
            res.pb(s[u]);
            u -= 1;
            v -= 1;
        }
        else{
            if(dp[u - 1][v] == dp[u][v]){
                u -= 1;
            }
            else{
                v -= 1;
            }
        }
    }

    reverse(res.begin(), res.end());
    if(res.size() <= 100){
        for(char c: res) cout << c;
    }
    else{
        int sz = res.size();
        int mid = res.size() / 2;
        if(res.size() % 2 == 1){
            mark[mid] = 1;
            sz -= 1;
        }
        int bd = 0, kt = res.size() - 1;
        while(sz > 100){
            sz -= 2;
            mark[bd] = 1;
            mark[kt] = 1;
            bd += 1;
            kt -= 1;
        }
        for(int i = 0; i < res.size(); i++){
            if(mark[i] == 0) cout << res[i];
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
