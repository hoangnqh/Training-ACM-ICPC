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
    int n;
    cin >> n;
    set<int> res;
    for(int i = 0; i <= 60; i++){
        int a = (1LL << i) - 1;
        int l = 1, r = min(1LL << 32, (a == 0) ? (1LL << 32) : ((1LL << 62) / a));
        int x = -1;
        //cout << r << endl;
        while(l <= r){
            int mid = (l + r) / 2;
            if(a * mid > n){
                r = mid - 1;
                continue;
            }
            if(mid * (mid - 1) / 2 > n){
                r = mid - 1;
                continue;
            }
            int val = a * mid + mid * (mid - 1) / 2;
            if(val < n){
                l = mid + 1;
            }
            if(val == n){
                x = mid;
                break;
            }
            if(val > n){
                r = mid - 1;
            }
        }
        if(x != -1 && x % 2 == 1){
            //cout << i << " " << x << endl;
            res.insert((1LL << i) * x);
        }

    }
    if(res.size() == 0) cout << -1 << '\n';
    for(int i: res) cout << i << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
