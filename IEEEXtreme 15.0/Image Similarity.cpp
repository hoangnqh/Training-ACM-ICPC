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

vector<vector<int> > a;
vector<vector<int> > key[8];
int ans[8];

vector<vector<int> > xoay(vector<vector<int> > a){
    int n = a.size();
    int m = a[0].size();
    vector<vector<int> > b(m, vector<int> (n, 0));
    for(int i1 = 0, i2 = 0; i2 < m; i1++, i2++){
        for(int j1 = 0, j2 = n - 1; j2 >= 0; j1++, j2--){
            b[i1][j1] = a[j2][i2];
        }
    }
    return b;
}

vector<vector<int> > lat(vector<vector<int> > a){
    int n = a.size();
    int m = a[0].size();
    vector<vector<int> > b(n, vector<int> (m, 0));
    for(int i1 = 0, i2 = 0; i2 < n; i1++, i2++){
        for(int j1 = 0, j2 = m - 1; j2 >= 0; j1++, j2--){
            b[i1][j1] = a[i2][j2];
        }
    }
    return b;
}

void solve(){
    int R, C;
    cin >> R >> C;
    vector<vector<int> > a(R, vector<int> (C, 0));
    for(int i = 0; i < R; i++){
        for(int j = 0; j < C; j++){
            char c;
            cin >> c;
            if(c == '.') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }

    key[0] = a;
    key[1] = lat(a);

    key[2] = xoay(key[0]);
    key[3] = lat(key[2]);

    key[4] = xoay(key[2]);
    key[5] = lat(key[4]);

    key[6] = xoay(key[4]);
    key[7] = lat(key[6]);

    int R2, C2;
    cin >> R2 >> C2;
    vector<vector<int> > b(90, vector<int> (90, 0));
    for(int i = 0; i < R2; i++){
        for(int j = 0; j < C2; j++){
            char c;
            cin >> c;
            if(c == '.') b[i + 30][j + 30] = 0;
            else b[i + 30][j + 30] = 1;
        }
    }
    R2 = 90;
    C2 = 90;

    int res = 0;
    for(int i = 0; i < R2; i++){
        for(int j = 0; j < C2; j++){
            for(int k = 0; k < 8; k++){
                int cnt = 0;
                for(int i1 = 0; i1 < key[k].size(); i1++){
                    for(int j1 = 0; j1 < key[k][i1].size(); j1++){
                        if(key[k][i1][j1] == 0) continue;
                        int i2 = i1 + i, j2 = j1 + j;
                        if(i2 < R2 && j2 < C2){
                            if(b[i2][j2] == 1) cnt += 1;
                        }
                        else break;
                    }
                }
                res = max(res, cnt);
            }
        }
    }
    cout << res << '\n';

}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T; while(T--)
    solve();
}
