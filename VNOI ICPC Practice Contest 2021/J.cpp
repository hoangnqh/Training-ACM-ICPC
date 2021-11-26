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
II a[N];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].fi >> a[i].se;
    }
    if(n == 1){
        cout << 1 << '\n';
        return;
    }
    int bd = 1;
    int res = 0;
    while(bd <= n){
        res += 1;
        set<int> s1, temp1;
        set<II> s2, temp2;
        s1.insert(a[bd].fi);
        s1.insert(a[bd].se);
        s2.insert(a[bd]);

        if(bd < n) for(int i = bd + 1; i <= n; i++){
            for(int val: s1){
                if(val == a[i].fi){
                    temp1.insert(a[i].fi);
                }
                if(val == a[i].se){
                    temp1.insert(a[i].se);
                }
                temp2.insert(mp(val, a[i].fi));
                temp2.insert(mp(val, a[i].se));
            }
            for(auto val: s2){
                if(val.fi == a[i].fi || val.fi == a[i].se || val.se == a[i].fi || val.se == a[i].se) temp2.insert(val);
            }

            if(temp1.size() == 0 && temp2.size() == 0){
                break;
                bd = i;
            }
            else bd = i + 1;

            s1 = temp1;
            s2 = temp2;
            temp1.clear();
            temp2.clear();
        }
        else break;
    }
    cout << res;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
