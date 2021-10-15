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
typedef vector<int> vi;
typedef vector<vi > vii;
typedef vector<vii > viii;
typedef vector<viii > viiii;
typedef vector<viiii > viiiii;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

const int INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 1e5 + 5;

int n;

int d[6];
int c[6];

int u[6], v[6];

int x[6], mark[6];

vector<int> bit[6];

int t[6];

void solve1(){
    int l = 1;
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }

    for(int i = 0; i < (1 << n); i++){
        int cnt = __builtin_popcount(i);
        bit[cnt].pb(i);
    }

    vi a(d[1] + 1, 0);

    for(int i1 = 1; i1 <= d[1]; i1++){
        cin >> a[i1];

        for(int i = 1; i <= n; i++){
            int val = 0;
            for(int mask: bit[i]){
                t[1] = i1;
                for(int j = 0; j < n; j++){
                    if(mask >> j & 1){
                        t[j + 1] -= 1;
                    }
                }
                val += a[t[1]];
            }

            if(i % 2 == 0) val = -val;
            a[i1] += val;
        }
    }


    int q;
    cin >> q;
    while(q--){
        for(int i = 1; i <= n; i++){
            cin >> u[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> v[i];
        }
        int ans = a[v[1]];
        for(int i = 1; i <= n; i++){
            int val = 0;
            for(int mask: bit[i]){
                for(int k = 1; k <= n; k++)
                    t[k] = u[k];
                for(int j = 0; j < n; j++){
                    if(mask >> j & 1){
                        t[j + 1] -= 1;
                    }
                }
                for(int k = 1; k <= n; k++){
                    if(t[k] == u[k]) t[k] = v[k];
                }

                val += a[t[1]];
            }
            if(i % 2 == 1) val = -val;
            ans += val;
        }
        cout << ans << '\n';
    }
}

void solve2(){
    int l = 1;
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }

    for(int i = 0; i < (1 << n); i++){
        int cnt = __builtin_popcount(i);
        bit[cnt].pb(i);
    }

    vii a(d[1] + 1, vi(d[2] + 1, 0));

    for(int i1 = 1; i1 <= d[1]; i1++){
        for(int i2 = 1; i2 <= d[2]; i2++){
            cin >> a[i1][i2];

            for(int i = 1; i <= n; i++){
                int val = 0;
                for(int mask: bit[i]){
                    t[1] = i1, t[2] = i2;
                    for(int j = 0; j < n; j++){
                        if(mask >> j & 1){
                            t[j + 1] -= 1;
                        }
                    }
                    val += a[t[1]][t[2]];
                }

                if(i % 2 == 0) val = -val;
                a[i1][i2] += val;
            }
        }
    }


    int q;
    cin >> q;
    while(q--){
        for(int i = 1; i <= n; i++){
            cin >> u[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> v[i];
        }
        int ans = a[v[1]][v[2]];
        for(int i = 1; i <= n; i++){
            int val = 0;
            for(int mask: bit[i]){
                for(int k = 1; k <= n; k++)
                    t[k] = u[k];
                for(int j = 0; j < n; j++){
                    if(mask >> j & 1){
                        t[j + 1] -= 1;
                    }
                }
                for(int k = 1; k <= n; k++){
                    if(t[k] == u[k]) t[k] = v[k];
                }
                val += a[t[1]][t[2]];
            }
            if(i % 2 == 1) val = -val;
            ans += val;
        }
        cout << ans << '\n';
    }
}

void solve3(){
    int l = 1;
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }

    for(int i = 0; i < (1 << n); i++){
        int cnt = __builtin_popcount(i);
        bit[cnt].pb(i);
    }

    viii a(d[1] + 1, vii(d[2] + 1, vi(d[3] + 1, 0)));

    for(int i1 = 1; i1 <= d[1]; i1++){
        for(int i2 = 1; i2 <= d[2]; i2++){
            for(int i3 = 1; i3 <= d[3]; i3++){
                cin >> a[i1][i2][i3];

                for(int i = 1; i <= n; i++){
                    int val = 0;
                    for(int mask: bit[i]){
                        t[1] = i1, t[2] = i2, t[3] = i3;
                        for(int j = 0; j < n; j++){
                            if(mask >> j & 1){
                                t[j + 1] -= 1;
                            }
                        }
                        val += a[t[1]][t[2]][t[3]];
                    }

                    if(i % 2 == 0) val = -val;
                    a[i1][i2][i3] += val;
                }
            }
        }
    }


    int q;
    cin >> q;
    while(q--){
        for(int i = 1; i <= n; i++){
            cin >> u[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> v[i];
        }
        int ans = a[v[1]][v[2]][v[3]];
        for(int i = 1; i <= n; i++){
            int val = 0;
            for(int mask: bit[i]){
                for(int k = 1; k <= n; k++)
                    t[k] = u[k];
                for(int j = 0; j < n; j++){
                    if(mask >> j & 1){
                        t[j + 1] -= 1;
                    }
                }
                for(int k = 1; k <= n; k++){
                    if(t[k] == u[k]) t[k] = v[k];
                }

                val += a[t[1]][t[2]][t[3]];
            }
            if(i % 2 == 1) val = -val;
            ans += val;
        }
        cout << ans << '\n';
    }
}

void solve4(){
    int l = 1;
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }

    for(int i = 0; i < (1 << n); i++){
        int cnt = __builtin_popcount(i);
        bit[cnt].pb(i);
    }

    viiii a(d[1] + 1, viii(d[2] + 1, vii(d[3] + 1, vi(d[4] + 1, 0))));

    for(int i1 = 1; i1 <= d[1]; i1++){
        for(int i2 = 1; i2 <= d[2]; i2++){
            for(int i3 = 1; i3 <= d[3]; i3++){
                for(int i4 = 1; i4 <= d[4]; i4++){
                    cin >> a[i1][i2][i3][i4];

                    for(int i = 1; i <= n; i++){
                        int val = 0;
                        for(int mask: bit[i]){
                            t[1] = i1, t[2] = i2, t[3] = i3, t[4] = i4;
                            for(int j = 0; j < n; j++){
                                if(mask >> j & 1){
                                    t[j + 1] -= 1;
                                }
                            }
                            val += a[t[1]][t[2]][t[3]][t[4]];
                        }

                        if(i % 2 == 0) val = -val;
                        a[i1][i2][i3][i4] += val;
                    }
                }
            }
        }
    }


    int q;
    cin >> q;
    while(q--){
        for(int i = 1; i <= n; i++){
            cin >> u[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> v[i];
        }
        int ans = a[v[1]][v[2]][v[3]][v[4]];
        for(int i = 1; i <= n; i++){
            int val = 0;
            for(int mask: bit[i]){
                for(int k = 1; k <= n; k++)
                    t[k] = u[k];
                for(int j = 0; j < n; j++){
                    if(mask >> j & 1){
                        t[j + 1] -= 1;
                    }
                }
                for(int k = 1; k <= n; k++){
                    if(t[k] == u[k]) t[k] = v[k];
                }

                val += a[t[1]][t[2]][t[3]][t[4]];
            }
            if(i % 2 == 1) val = -val;
            ans += val;
        }
        cout << ans << '\n';
    }
}

void solve5(){
    int l = 1;
    for(int i = 1; i <= n; i++){
        cin >> d[i];
    }

    for(int i = 0; i < (1 << n); i++){
        int cnt = __builtin_popcount(i);
        bit[cnt].pb(i);
    }

    viiiii a(d[1] + 1, viiii(d[2] + 1, viii(d[3] + 1, vii(d[4] + 1, vi(d[5] + 1, 0)))));

    for(int i1 = 1; i1 <= d[1]; i1++){
        for(int i2 = 1; i2 <= d[2]; i2++){
            for(int i3 = 1; i3 <= d[3]; i3++){
                for(int i4 = 1; i4 <= d[4]; i4++){
                    for(int i5 = 1; i5 <= d[5]; i5++){
                        cin >> a[i1][i2][i3][i4][i5];

                        for(int i = 1; i <= n; i++){
                            int val = 0;
                            for(int mask: bit[i]){
                                t[1] = i1, t[2] = i2, t[3] = i3, t[4] = i4, t[5] = i5;
                                for(int j = 0; j < n; j++){
                                    if(mask >> j & 1){
                                        t[j + 1] -= 1;
                                    }
                                }
                                val += a[t[1]][t[2]][t[3]][t[4]][t[5]];
                            }

                            if(i % 2 == 0) val = -val;
                            a[i1][i2][i3][i4][i5] += val;
                        }
                    }
                }
            }
        }
    }


    int q;
    cin >> q;
    while(q--){
        for(int i = 1; i <= n; i++){
            cin >> u[i];
        }
        for(int i = 1; i <= n; i++){
            cin >> v[i];
        }
        int ans = a[v[1]][v[2]][v[3]][v[4]][v[5]];
        for(int i = 1; i <= n; i++){
            int val = 0;
            for(int mask: bit[i]){
                for(int k = 1; k <= n; k++)
                    t[k] = u[k];
                for(int j = 0; j < n; j++){
                    if(mask >> j & 1){
                        t[j + 1] -= 1;
                    }
                }
                for(int k = 1; k <= n; k++){
                    if(t[k] == u[k]) t[k] = v[k];
                }

                val += a[t[1]][t[2]][t[3]][t[4]][t[5]];
            }
            if(i % 2 == 1) val = -val;
            ans += val;
        }
        cout << ans << '\n';
    }
}


int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    if(n == 1) solve1();
    if(n == 2) solve2();
    if(n == 3) solve3();
    if(n == 4) solve4();
    if(n == 5) solve5();
}

/**
2
3 3
1 2 3
4 5 6`
7 8 9
1
1 3
3 3
*/
