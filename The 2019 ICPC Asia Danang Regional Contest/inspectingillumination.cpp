#include<bits/stdc++.h>
using namespace std;

const int N = 2005;

int n;

// First way
set<int> a[N];
void firstWay(){
    cin >> n;

    if(n == 1){
        cout << "ANSWER 1" << endl;
        return;
    }
    for(int i = 1; i <= n; i++){
        for(int j = n + 1; j <= 2 * n; j++){
            a[i].insert(j);
            a[j].insert(i);
        }
    }
    vector<pair<int, int> > s, s2;
    s.push_back({1, n});
    int cnt = 0;
    while(1){
        if(s.size() == 0){
            cout << "ANSWER";
            for(int i = n + 1; i <= 2 * n; i++){
                cout << " " << *a[i].begin();
            }
            cout << endl;
            return;
        }
        set<int> query;
        for(int i = 0; i < s.size(); i++){
            if(s[i].first == s[i].second) continue;
            int mid = (s[i].first + s[i].second) / 2;

            for(int j = s[i].first; j <= mid; j++){
                query.insert(j);
            }

            if(s[i].first < mid) s2.push_back({s[i].first, mid});
            if(mid + 1 < s[i].second) s2.push_back({mid + 1, s[i].second});
        }
        s = s2; s2.clear();
        if(query.size() == 0){
            while(1) {}
        }
        cout << "ASK " << query.size();
        for(int i: query) cout << " " << i;
        cout << endl;

        set<int> ans;
        for(int i = 1; i <= query.size(); i++){
            int x; cin >> x; x += n;
            ans.insert(x);
        }

        for(int it: query){
            vector<int> temp;
            for(int u: a[it]){
                if(ans.count(u)) continue;
                temp.push_back(u);
            }
            for(int u: temp){
                a[it].erase(u);
                a[u].erase(it);

            }
        }

        for(int it: ans){
            vector<int> temp;
            for(int u: a[it]){
                if(query.count(u)) continue;
                temp.push_back(u);
            }
            for(int u: temp){
                a[it].erase(u);
                a[u].erase(it);
            }
        }
    }
}

// Second way
// Best solution
int bit[1005][35];
int ans[1005];
void secondWay(){
    cin >> n;

    int cntQuery = log2(n);

    for(int t = 0; t <= cntQuery; t++){

        vector<int> ask;
        for(int i = 1; i <= n; i++){
            if(i >> t & 1) ask.push_back(i);
        }

        // ASK
        cout << "ASK "; cout << ask.size() << " "; for(int it: ask) cout << it << " ";
        cout << endl;

        // READ
        for(int i = 1; i <= ask.size(); i++){
            int x; cin >> x;
            bit[x][t] = 1;
        }
    }

    // Caculate
    for(int i = 1; i <= n; i++){
        for(int t = 0; t <= cntQuery; t++){
            ans[i] += bit[i][t] << t;
        }
    }

    // ANSWER
    cout << "ANSWER ";
    for(int i = 1; i <= n; i++){
        cout << ans[i] << " ";
    }
    cout << endl;
}


int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    secondWay();
}
