#include<bits/stdc++.h>>
using namespace std;

#define int long long

bool mark[1000006];
vector<int> a[100005];

int get(int a, int b){
    int ans = 1;
    while(a % b == 0){
        ans += 1;
        a /= b;
    }
    return ans;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t, L, R;
    cin >> t >> L >> R;

    for(int i = 2; i * i <= 1000000; i++){
        if(mark[i]) continue;
        for(int j = i * i; j <= 1000000; j += i){
            mark[j] = 1;
        }
    }

    for(int i = 2; i <= 1000000; i++){
        if(mark[i]) continue;
        int start = ((L - 1) / i + 1) * i;
        for(; start <= R; start += i){
            a[start - L].push_back(i);
        }
    }

    for(int i = L; i <= R; i++){
        int val = i;
        for(int prime: a[i - L]){
            while(val % prime == 0) val /= prime;
        }
        if(val > 1) a[i - L].push_back(val);
    }

    while(t--){
        int d; /// d is prime
        cin >> d;
        int res = 0;
        for(int i = L; i <= R; i++){
            int divisor = 1;
            for(int prime: a[i - L]){
                if(prime == d) continue;
                divisor *= get(i, prime);
            }
            res += divisor;
        }
        cout << res << '\n';
    }
}
