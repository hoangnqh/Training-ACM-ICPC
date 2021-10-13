#include <bits/stdc++.h>


using namespace std;

const int maxn = 1e3+5;

int w,n;
int val[maxn];
int wt[maxn];

int solve(){
    int dp[w+1];
    memset(dp,0,sizeof dp);

    for(int i = 1; i < n +1; i++){
        for(int j = w; j >= 0; j--){
            if(wt[i-1] <= j){
                dp[j] = max(dp[j],dp[j - wt[i-1]] + val[i-1]);
            }
        }
    }

    return dp[w];
}

int main(){
    int t;
    cin >> t;
    while(t--){
       cin >> w >> n;
       for(int i = 0; i < n; i++){
            cin >> wt[i] >> val[i];
       }

       cout << solve() << endl;
    }

}
