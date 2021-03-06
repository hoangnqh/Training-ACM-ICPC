#include<bits/stdc++.h>
using namespace std;

#define next dsfdsf
#define right asgkjas
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

string s;
int n, query;
string t[20000 + 5];
vector<III> q[500 + 5];

int res[300000 + 5];

int next[500 + 5][26 + 5];
II right[20000 + 5];

int total = 0;
int bit[20000 + 5];

void initBIT(){
    total = 0;
    for(int id = 1; id <= n; id++){
        bit[id] = 0;
    }
}

void update(int x, int val){
    total += val;
    for(; x <= n; x += x&-x){
        bit[x] += val;
    }
}

int getCnt(int mid){
    int ans = 0;
    for(; mid >= 1; mid -= mid&-mid)
        ans += bit[mid];
    return ans;
}

int get(int k){
    if(k > total) return -1;
    int l = 1, r = n;
    int res = -1;
    while(l <= r){
        int m = (l + r) / 2;
        int val =getCnt(m);
        if(val >= k){
            res = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    return res;
}

void initRight(int left){
    for(int i = 1; i <= n; i++){
        right[i] = mp(1e9, i);
    }
    for(int i = 1; i <= n; i++){
        int pos = left;
        for(int j = 0; j < t[i].size(); j++){
            int c = t[i][j] - 'a';
            // jump to optimize complexity
            pos = next[pos][c];
            if(pos >= s.size()) break;
            if(j == t[i].size() - 1){
                //Got enough i-th dictionary
                right[i] = mp(pos, i);
            }
            pos += 1;
        }
    }
    sort(right + 1, right + n + 1);
}

void solve(){
    cin >> s;
    cin >> n >> query;
    for(int i = 1; i <= n; i++){
        cin >> t[i];
    }
    sort(t + 1, t + n + 1);
    for(int i = 1; i <= query; i++){
        int l, r, k;
        cin >> l >> r >> k;
        l -= 1, r -= 1;
        q[l].pb(mp(r, mp(k, i))); // Offline process
    }

    for(int i = 0; i < s.size() + 5; i++){
        for(int j = 0; j <= 25; j++){
            next[i][j] = 1e9;
        }
    }
    for(int i = s.size() - 1; i >= 0; i--){
        for(char c = 'a'; c <= 'z'; c++){
            if(s[i] == c){
                next[i][c - 'a'] = i;
            }
            else{
                next[i][c - 'a'] = next[i + 1][c - 'a'];
            }
        }
    }

    for(int l = 0; l < s.size(); l++){
        if(q[l].size() == 0) continue;
        sort(q[l].begin(), q[l].end());
        initRight(l);
        initBIT();

        int id = 1;
        for(auto it: q[l]){
            int r = it.fi, k = it.se.fi, i = it.se.se;

            while(id <= n && r >= right[id].fi){
                update(right[id].se, 1);
                id += 1;
            }
            res[i] = get(k);
        }
    }

    for(int i = 1; i <= query; i++){
        if(res[i] == -1){
            cout << "NO SUCH WORD" << '\n';
            continue;
        }
        string ans = t[res[i]];
        if(ans.size() > 10) ans = ans.substr(0, 10);
        cout << ans << '\n';
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
