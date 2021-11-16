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



void solve(){
    int res = 0;
    int n;
    cin >> n;
    for(int i = 1; i <= INF; i++){
        int val = i;
        vector<int> temp;
        while(val > 0){
            temp.pb(val % 2);
            val /= 2;
        }
        reverse(temp.begin(), temp.end());
        int x = 0;
        for(int i: temp){
            x = x * 10 + i;
        }
        if(x > n) break;
        res += 1;
    }
    cout << res;

}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
