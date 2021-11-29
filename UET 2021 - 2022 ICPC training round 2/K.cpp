#include<bits/stdc++.h>
using namespace std;
#define int long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
typedef pair<int, int >ii;
typedef pair<int, ii> iii;
const int INF = 1e10;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
typedef tuple<int, int, char> tiic;
void solve() {
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    set<char> st;
    int n1 = s1.size();
    int n2 = s2.size();
    int j = 0;
    for(int i = 0; i < n1; i++){
        int cnt1 = 0, cnt2 = 0;
        for(int t = i; t < n1; t++){
            if(s1[t] == s1[i]) cnt1++;
        }
        for(int t = j; t < n2; t++){
            if(s2[t] == s2[j]) cnt2++;
        }
        if(cnt2 == 2 * cnt1){
            st.insert(s1[i]);
            j += 2;
        }
        else j += 1;
    }

    for (auto x : st) {
        cout << x;
    }

}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "r", stdin);
//freopen("output.txt", "w", stdout);
//#endif
    int t = 1;
    //cin >> t;
    while (t--) solve();
}
