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



void solve(){
    string s;
    int n;
    cin >> s;
    cin >> n;
    map<char, int> m, m2;
    set<char> Set;
    for(char c: s){
        Set.insert(c);
        m[c]++;
    }
    if(Set.size() > n){
        cout << -1;
        return;
    }
    n -= Set.size();
    vector<char> res;
    for(char c: Set){
        res.pb(c);
        m2[c]++;
        m[c]--;
    }

    for(int i = 1; i <= n; i++){
        pair<char, int> x = {'a', -INF};
        for(char c: Set){
            int val = (m[c] - 1) / m2[c] + 1;
            if(m[c] <= 0) val = 0;
            if(val > x.se){
                x = mp(c, val);
            }
        }
        m[x.fi] -= 1;
        m2[x.fi] += 1;
        res.pb(x.fi);
    }
    int xx = 0;
    for(char c: Set){
        int val = (m[c] - 1) / m2[c] + 1;
        if(m[c] <= 0) val = 0;
        if(val > xx){
            xx = val;
        }
    }

    cout << xx + 1 << '\n';
    for(auto c: res) cout << c;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
