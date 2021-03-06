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
    int w;
    cin >> w;
    for(int i = 1; i <= w; i++){
        int a = i, b = w - i;
        if( a > 0 && b > 0 && a % 2 == 0 && b % 2 == 0){
            cout << "YES";
            return;
        }
    }
    cout << "NO";
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
