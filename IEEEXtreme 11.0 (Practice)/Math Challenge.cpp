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
const int N = 1e6 + 5;

int gt[N];
int PHI;

int phi(int n){
    int result = n;
    for(int p = 2; p * p <= n; ++p){
        if (n % p == 0){
            while (n % p == 0)
                n /= p;

            result -= result / p;
        }
    }

    if (n > 1)
        result -= result / n;

    return result;
}

int POW(int a, int b, int M){
    if(b == 0) return 1;
    if(b == 1) return a;
    int c = POW(a, b / 2, M);
    c = (c * c) % M;
    if(b % 2 == 1) c = (c * a) % M;
    return c;
}

int C(int k, int n){
    return (gt[n] * POW((gt[k] * gt[n - k]) % (MOD - 1), phi(MOD - 1) - 1, MOD - 1)) % (MOD - 1);
}

int c[1005][1005];
int Ckn(int k, int n){
    if(c[k][n] != -1) return c[k][n];
    if(k > n) return 0;
    if(k == 1) return n;
    if(k == 0) return 1;
    return c[k][n] = (Ckn(k - 1, n - 1) + Ckn(k, n - 1)) % (MOD - 1);
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    gt[0] = 1;
    gt[1] = 1;
    for(int i = 2; i <= 1000000; i++){
        gt[i] = (gt[i - 1] * i) % (MOD - 1);
    }
    for(int i = 1; i <= 1000; i++){
        for(int j = 1; j <= 1000; j++){
            c[i][j] = -1;
        }
    }

    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        int x = 1;
        if(c <= 1000 && b <= 1000) x = Ckn(c, b);
        else x = C(c, b);
        cout << POW(a, x, MOD) << '\n';
    }


}
