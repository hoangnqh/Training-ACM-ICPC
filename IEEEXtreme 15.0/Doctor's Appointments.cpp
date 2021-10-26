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

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

const int INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

III a[N];
int trace[N];
int x[N];
int n;

bool cmp(III a, III b) {
    return (a.se.fi - a.fi) < (b.se.fi - b.fi);
}
void solve() {


    set<int> st;
    for (int i = 1; i <= n; i++) {
        st.insert(i);
    }

    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se.fi;
        a[i].se.se = i;
    }

    sort(a + 1, a + n + 1, [&](III x, III y) {
        if (x.se.fi - y.fi == y.se.fi - y.fi) {
            return x.fi < y.fi;
        }
        return (x.se.fi - y.fi) < (y.se.fi - y.fi);
        });
    // for (int i = 1; i <= n; i++) {
    //     cout << a[i].fi << " " << a[i].se.fi << endl;
    // }
    int ans[n + 1];
    for (int i = 1; i <= n;i++) {
        int tmp = *st.lower_bound(a[i].fi);
        //    cout << tmp << '\n';
        if (tmp > a[i].se.fi) {
            cout << "impossible" << '\n';
            return;
        }
        st.erase(tmp);
        ans[tmp] = a[i].se.se;
    }

    for (int i = 1; i <= n; i++) {
        cout << ans[i] << " ";
    }
    cout << '\n';
}

void trau(){
    for (int i = 1; i <= n; i++) {
        cin >> a[i].fi >> a[i].se.fi;
        a[i].se.se = i;
    }
    for(int i = 1; i <= n; i++){
        x[i] = i;
    }
    do{
        int cnt = 0;
        for(int i = 1; i <= n; i++){
            if(a[i].fi <= x[i] && x[i] <= a[i].se.fi){
                cnt += 1;
                trace[x[i]] = a[i].se.se;
            }
        }
        if(cnt == n){
            for(int i = 1; i <= n; i++){
                cout << trace[i] << " ";
            }
            cout << '\n';
            return;
        }
    }while(next_permutation(x + 1, x + n + 1));
    cout << "impossible" << '\n';
}

int32_t main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int T; cin >> T; while (T--){
        cin >> n;
        if(n <= 10) trau();
        else solve();
    }
}
/**


1
5
1 3
2 5
2 2
2 3
4 5

1 4 2 3 5
*/
