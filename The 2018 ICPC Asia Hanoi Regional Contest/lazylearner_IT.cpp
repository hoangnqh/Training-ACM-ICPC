#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define pb push_back
#define mp make_pair

typedef pair<int, int> II;
typedef pair<int, II> III;

int len;
string s;
int n, Q;
string t[20004];
vector<III> fr[502];
II ed[20004];
int res[300005];

int st[4 * 20004];

void initST(){
    for(int i = 1; i <= 4 * 20000; i++){
        st[i] = 0;
    }
}

void update(int pos){
    int id = 1, l = 1, r = n;
    while(l < r){
        int m = (l + r) >> 1;
        if(pos <= m){
            id = id << 1;
            r = m;
        }
        else{
            id = id << 1 | 1;
            l = m + 1;
        }
    }
    st[id] += 1;
    while(id > 1){
        id = id >> 1;
        st[id] = st[id << 1] + st[id << 1 | 1];
    }
}

III Stack[100];
int get(int k){
    int i = 1;
    Stack[i] = mp(1, mp(1, n));
    while(i){
        int id = Stack[i].fi, l = Stack[i].se.fi, r = Stack[i].se.se;
        i--;
        if(k > st[id]) return -1;
        if(l == r) return l;
        int m = (l + r) >> 1;
        if(k <= st[id << 1]){
            i++;
            Stack[i] = mp(id << 1, mp(l, m));
        }
        else{
            i++;
            Stack[i] = mp(id << 1 | 1, mp(m + 1, r));
            k -= st[id << 1];
        }
    }
}

void initEnd(int u){
    for(int i = 1; i <= n; i++){
        ed[i] = mp(len + 1, i);
        int check = 1;
        int p = u;
        for(int j = 0; j < t[i].size(); j++){
            while(p <= len && s[p] != t[i][j]) p++;
            if(p > len) check = 0;
            p++;
        }
        if(check) ed[i] = mp(p - 1, i);
    }
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> s;
    len = s.size();
    s = '@' + s;
    cin >> n >> Q;
    for(int i = 1; i <= n; i++){
        cin >> t[i];
    }
    for(int i = 1; i <= Q; i++){
        int u, v, k;
        cin >> u >> v >> k;
        fr[u].pb(mp(v, mp(k, i)));
    }

    sort(t + 1, t + n + 1);
    for(int u = 1; u <= len; u++){
        sort(fr[u].begin(), fr[u].end());
        initEnd(u);
        sort(ed + 1, ed + n + 1);
        initST();
        int j = 1;
        for(auto it: fr[u]){
            int v = it.fi, k = it.se.fi, pos = it.se.se;
            while(j <= n && ed[j].fi <= v){
                update(ed[j].se);
                j++;
            }
            res[pos] = get(k);
        }
    }

    for(int i = 1; i <= Q; i++){
        if(res[i] == -1){
            cout << "NO SUCH WORD" << '\n';
        }
        else{
            for(int j = 0; j < min((int)t[res[i]].size(), 10); j++){
                cout << t[res[i]][j];
            }
            cout << '\n';
        }
    }
}
