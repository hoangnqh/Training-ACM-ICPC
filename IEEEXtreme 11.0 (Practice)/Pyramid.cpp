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

map<vector<int>, int> m;

int solve(vector<int> x){
    if(m.count(x)) return m[x];
    int res = 1;
    int val = INF;
    for(int i: x) val = min(val, i);
    if(val < 2) m[x] = res;
    for(int i = 1; i <= x[0] - 1; i++){
        vector<int> temp;
        temp.pb(i);
        for(int j = 0; j < x.size(); j++){
            int s = x[j] - temp.back();
            if(s < 1) break;
            temp.pb(s);
        }
        if(temp.size() < x.size() + 1) continue;
        res += solve(temp);
    }
    return m[x] = res;
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)

    for(int i = 1; i <= 50; i++){
        cout << solve(vector<int> {i}) << endl;
    }
}
