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
    if(n % 2 == 1){
        cout << -1 << '\n';
        return;
    }
    vector<int> v;
    for(int i = 1; i <= 1000005; i++){
        int val = n / (i * (i + 1));
        if (val * i * (i + 1) == n){
            v.push_back(i);
        }
        val = n;
        if(val % i == 0){
            val = val / i;
            int x = sqrt(val);
            if(x * (x + 1) == val) v.push_back(x);
        }
    }
    set<int> s;
    for(int i: v)
        s.insert(i);
    for(int i: s){
        cout << i << " ";
    }
    cout << '\n';


}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T; while(T--)
    solve();
}
