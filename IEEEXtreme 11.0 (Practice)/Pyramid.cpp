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

int f[N], f2[N];

int c[20][20];
int nCr(int n, int r){
    if(c[n][r] != -1) return c[n][r];
    if(r > n) return 0;
    if(r == 0) return 1;
    if(r == 1) return n;
    if(r == n) return 1;
    return c[n][r] = nCr(n - 1, r - 1) + nCr(n - 1, r);
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    int s;
    cin >> s;

    for(int i = 0; i < 20; i++){
        for(int j = 0; j < 20; j++){
            c[i][j] = -1;
        }
    }

    int res = 0;
    f[0] = 1;
    for(int i = 0; i <= 16; i++){
        int val = s - (1 << i);
        if(val <= 0){
            if(val == 0) res = (res + 1) % MOD;
            break;
        }
        for(int j = 1; j <= val; j++){
            f[j] = 0;
        }
        for(int t = 0; t <= i; t++){
            int x = nCr(i, t);
            for(int j = 0; j <= val; j++){
                if(j + x > val) continue;
                f[j + x] += f[j];
                f[j + x] %= MOD;
            }

        }
        res = (res + f[val]) % MOD;
    }

    cout << res;
}
