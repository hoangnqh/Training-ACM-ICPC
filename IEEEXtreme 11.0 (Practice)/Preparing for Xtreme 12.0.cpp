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

map<string, int> Map;
int book = 0, topic = 0;

int f[1 << 20];
II q[105];

int32_t main()
{
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
    freopen("test.txt", "r", stdin);
    string s;
    while(getline(cin, s)){
        book += 1;
        s.pb(' ');
        int i = 0;
        int val = 0;
        while(i < s.size() && '0' <= s[i] && s[i] <= '9'){
            val = val * 10 + (int)(s[i] - '0');
            i += 1;
        }

        i += 1;
        int mask = 0;
        string x = "";
        while(i < s.size()){
            if(s[i] == ' '){
                if(!Map.count(x)){
                    topic += 1;
                    Map[x] = topic;
                }
                mask += (1 << (Map[x] - 1));
                x = "";
            }
            else{
                x.pb(s[i]);
            }
            i++;
        }
        q[book] = mp(val, mask);
    }

    for(int i = 0; i < (1 << topic); i++){
        f[i] = INF;
    }
    f[0] = 0;
    for(int i = 1; i <= book; i++){
        for(int t = 0; t < (1 << topic); t++){
            if(f[t] == INF) continue;
            int mask = t | q[i].se;
            f[mask] = min(f[mask], f[t] + q[i].fi);
        }
    }

    cout << f[(1 << topic) - 1];
}
