// https://csacademy.com/ieeextreme-practice/task/7df0da0b0477307be410f4772c739528/
#include<bits/stdc++.h>
using namespace std;

#define int long long

const int MOD = 1e9 + 7;
const int PHI = 1e9 + 6;
int P[] = {2, 500000003};
const int N = 1e6 + 5;

int gt[2][N];

int power(int a, int b, int M){
    if(b == 0) return 1;
    if(b == 1) return a;
    int c = power(a, b / 2, M);
    c = (c * c) % M;
    if(b % 2 == 1) c = (c * a) % M;
    return c;
}

// Modular Multiplicative Inverse
int inv(int a, int m){
    return power(a, m - 2, m);
}

// Chinese Remainder Theory
int CRT(vector<pair<int, int> > x){
    int prod = 1;
    int k = x.size();
    for (int i = 0; i < x.size(); i++)
        prod *= x[i].first;

    int result = 0;
    for (int i = 0; i < x.size(); i++) {
        int pp = prod / x[i].first;
        result += x[i].second * inv(pp, x[i].first) * pp;
    }
    return result % prod;
}

int nCr(int n, int r, int pos){
    if(r > n) return 0;
    int inv1 = power(gt[pos][r], P[pos] - 2, P[pos]);
    int inv2 = power(gt[pos][n - r], P[pos] - 2, P[pos]);
    return (((gt[pos][n] * inv1) % P[pos]) * inv2) % P[pos];
}

vector<int> getDigit(int N, int M) {
    vector<int> res;
    while (N > 0) {
        res.push_back(N % M);
        N /= M;
    }
    return res;
}

// Lucas Theory
int nCr_Lucas(int N, int K, int M){
    vector<int> n = getDigit(N, M);
    vector<int> k = getDigit(K, M);
    long long res = 1;
    for (int i = 0; i < k.size(); ++i) {
        res = (res * nCr(n[i], k[i], 0)) % M;
    }
    return res;
}

int nCr(int n, int r){
    vector<pair<int, int> > x;
    x.push_back(make_pair(P[0], nCr_Lucas(n, r, 2)));
    x.push_back(make_pair(P[1], nCr(n, r, 1)));
    return CRT(x);
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    gt[0][0] = 1; gt[1][0] = 1;
    for(int i = 1; i <= 1000000; i++){
        gt[0][i] = (gt[0][i - 1] * i) % P[0];
        gt[1][i] = (gt[1][i - 1] * i) % P[1];
    }

    int t;
    cin >> t;
    while(t--){
        int a, b, c;
        cin >> a >> b >> c;
        cout << power(a, nCr(b, c), MOD) << '\n';
    }
}
