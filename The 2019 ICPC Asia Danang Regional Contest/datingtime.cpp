#include<bits/stdc++.h>
using namespace std;
#define int long long 
#define fi first 
#define se second 
#define mp make_pair 
#define pb push_back 
typedef pair<int, int >ii;
typedef pair<int, ii> iii;
const int INF = 1e9;
const int MOD = 1e9 + 7;
const int N = 2e5 + 5;
char cach[N];
vector<double> Time[3];
double t[3];
void tao() {
    t[0] = 0;
    t[1] = double(3) / 11;
    t[2] = double(6) / 11;
    double delta = double(12) / 11;
    for (int i = 0; i < 3; i++) {
        while (t[i] <= 24) {
            Time[i].pb(t[i]);
            t[i] += delta;
        }
    }
    t[1] = double(9) / 11;
    while (t[1] <= 24) {
        Time[1].pb(t[1]);
        t[1] += delta;
    }
    sort(Time[1].begin(), Time[1].end());
}
double readTime(string s) {
    string h = "";
    string m = "";
    h = h + s[0] + s[1];
    m = m + s[3] + s[4];
    double Hour = double(stoi(h));
    double Minute = double(stoi(m));
    double res = Hour + Minute / 60;
    return res;
}
void solve() {
    string s1, s2;
    int type;
    cin >> s1 >> s2 >> type;
    type /= 90;
    double l = readTime(s1);
    double r = readTime(s2);
    int l1 = -1, r1 = -1;
    // cout << l << " " << r << endl;
    for (int i = 0; i < (int)Time[type].size(); i++) {
        // cout << Time[type][i] << " ";
        if (double(l) <= double(Time[type][i]) + 0.0000001 && l1 < 0) l1 = i;
        if (r >= Time[type][i]) r1 = i;
    }
    cout << r1 - l1 + 1 << endl;
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    tao();
    int k = 1;
    cin >> k;
    while (k--) {
        solve();
    }
}