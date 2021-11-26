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
int mark[10];

struct node{
    int x1, y1, x2, y2;
};

node a[10];

void solve(){
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i].x1 >> a[i].y1 >> a[i].x2 >> a[i].y2;
    }
    for(int t = 1; t < (1 << n); t++){
        t = (1 << n) - 1;
        vector<node> temp;
        for(int i = 1; i <= n; i++){
            if(t >> (i - 1) & 1) temp.pb(a[i]);
        }
        II A = {INF, INF}, C = {-INF, -INF};
        int S = 0;
        for(int i = 0; i < temp.size(); i++){
            S += (temp[i].x2 - temp[i].x1) * (temp[i].y2 - temp[i].y1);
            A.fi = min(A.fi, temp[i].x1);
            A.se = min(A.se, temp[i].y1);
            C.fi = max(C.fi, temp[i].x2);
            C.se = max(C.se, temp[i].y2);
        }
        if(C.fi - A.fi != C.se - A.se) continue;
        if((C.fi - A.fi) * (C.se - A.se) != S) continue;
        cout << "YES";
        return;
    }
    cout << "NO";
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
