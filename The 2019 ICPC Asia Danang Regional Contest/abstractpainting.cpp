#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mod = 1e9 + 7;

int32_t main(){
    int t;
    cin >> t;
    while(t--){
        int ans = 1;

        int r,c;
        cin >> r >> c;

        for(int i = 1; i <= r; i++){
            ans = (ans*3)%mod;
        }

        for(int i = 1; i<= c; i++){
            ans = (ans*3)%mod;
        }

        for(int i = 1; i<= r*c; i++){
            ans = (ans*2)%mod;
        }

        cout << ans << endl;
    }
}
