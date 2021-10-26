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
const int N = 2e6 + 5;

void solve(){
    int n, k;
    cin >> n >> k;
    set<int> st;
    vector<int> a(n + 5, 0), dp(n + 5, 0), x(n + 5, 0), mark(n + 5, 0), temp;
    string s;
    for(int i = 1; i <= n; i++){
        cin >> s;
        int val = 0;
        for(char c: s){
            val = val * 27 + (c - 'a' + 1);
        }
        a[i] = val;
        st.insert(val);
    }
    for(int i: st){
        temp.push_back(i);
    }
    for(int i = 1; i <= n; i++){
        a[i] = lower_bound(temp.begin(), temp.end(), a[i]) - temp.begin() + 1;
        //cout << a[i] << " ";
    }
    //cout << '\n';

    for(int i = 1; i <= n; i++){
        if(mark[a[i]] == 0) dp[i] += 1, dp[i] %= MOD;
        mark[a[i]] = 1;
        if(i - k - 1 >= 1){
            dp[i] += (dp[i - 1] + dp[i - k - 1] - x[a[i]] + MOD * MOD) % MOD;
            x[a[i]] = dp[i - k - 1];
            dp[i] %= MOD;
        }
        else{
            dp[i] += dp[i - 1];
            dp[i] %= MOD;
        }
    }
    cout << dp[n] << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T; while(T--)
    solve();
}
/**
2
7 1
a
abc
abc
a
dac
a
a
7 2
a
abc
abc
a
dac
a
a
*/
