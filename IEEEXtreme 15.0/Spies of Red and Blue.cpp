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

vector<vector<int> > a;
int mark[2005];

int NR, NB, E;

int dinh(string s){
    int val = 0;
    int cnt = 0;
    if(s[0] == 'B') val = NR;
    for(int i = 1; i < s.size(); i++){
        cnt = cnt * 10 + s[i] - '0';
    }
    return cnt + val;
}

II bfs(int p){
    for(int i = 1; i <= NR + NB; i++){
        mark[i] = 0;
    }
    queue<II> q;
    q.push(mp(0, p));
    mark[p] = 1;
    while(q.size()){
        int d = q.front().fi, u = q.front().se;
        q.pop();
        if(u == 1) return {1, d};
        if(u == NR + 1) return {NR + 1, d};

        for(int v: a[u]){
            if(mark[v]) continue;
            mark[v] = 1;
            q.push(mp(d + 1, v));
        }
    }
    return {-1, -1};
}


void solve(){
    cin >> NR >> NB >> E;
    a.clear();
    a = vector<vector<int> > (NR + NB + 5);
    for(int i = 1; i < NR; i++){
        string s;
        cin >> s;
        int p = dinh(s);
        int u = i + 1;
        a[u].pb(p);
        //cout << u << " " << p << '\n';
    }

    for(int i = 1; i < NB; i++){
        string s;
        cin >> s;
        int p = dinh(s);
        int u = i + 1 + NR;
        a[u].pb(p);
        //cout << u << " " << p << '\n';
    }

    //cout << '\n';
    while(E--){
        char c;
        string s1, s2;
        cin >> c >> s1 >> s2;
        int u = dinh(s1), v = dinh(s2);
        //cout << u << " " << v << '\n';
        if(c == 'w'){
            II val1 = bfs(u);
            II val2 = bfs(v);

            if(val1.fi == -1 && val2.fi == -1){
                cout << "NONE" << '\n';
                continue;
            }

            if(val1.fi == -1){
                if(val2.fi == 1){
                    cout << "RED" << " " << val2.se << '\n';
                }
                else{
                    cout << "BLUE" << " " << val2.se << '\n';
                }
                continue;
            }

            if(val2.fi == -1){
                if(val1.fi == 1){
                    cout << "RED" << " " << val1.se << '\n';
                }
                else{
                    cout << "BLUE" << " " << val1.se << '\n';
                }
                continue;
            }

            if(val1.first != val2.first && val1.second == val2.second){
                cout << "TIE" << " " << val1.second << '\n';
                continue;
            }

            if(val1.se < val2.se){
                if(val1.first == 1){
                    cout << "RED" << " " << val1.second << '\n';
                }
                else{
                    cout << "BLUE" << " " << val1.second << '\n';
                }
                continue;
            }
            else{
                if(val2.first == 1){
                    cout << "RED" << " " << val2.second << '\n';
                }
                else{
                    cout << "BLUE" << " " << val2.second << '\n';
                }
                continue;
            }

        }
        else{
            a[u].clear();
            a[u].push_back(v);
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T; while(T--)
    solve();
}

/**
1
4 4 7
R1 R2 R3
B1 B1 B2
w R2 B2
w R4 B3
c B2 R3
w R4 B2
c R3 B4
w R4 B2
w R4 B3
*/
