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
int chay[100];
void tao() {
    chay[1] = 0;
    chay[2] = 9;

    for (int i = 3; i <= 15; i++) {
        chay[i] = chay[i - 1] + 10 * (i - 2) + 9;
    }
}
bool fullZero(string s) {
    int n = (int)s.size();
    for (int i = 1; i < n - 1; i++) {
        if (s[i] > '0') return false;
    }
    if (s[n - 1] == '0') return true;

    return false;
}
bool chi2so(string s) {
    int dem = 0;
    int n = s.size();
    for (int i = 1; i < n - 1; i++) {

        if (s[i] == '1') dem++;

    }
    if (dem >= 1) return true;
    else return 0;
}
void solve() {
    int res = 0;
    string s;
    cin >> s;
    int n = (int)s.size();
    res += chay[n];
    if (n == 1) {
        cout << s[0] - '1' << endl;
        return;
    }
    if (fullZero(s) && s[0] == '1') {
        cout << res << endl;
        return;
    }
    else if (fullZero(s)) {
        s[0] = s[0] - 1;
        for (int i = 1; i < n; i++) {
            s[i] = '9';
        }
        res++;
    }

    if (s[0] != '1') {
        res += (s[0] - '0');
    }

    for (int i = 1; i < n; i++) {
        while (s[i] == '0' && i < n - 1) i++;
        if (i == n - 1) {
            res += (s[i] - '0');
        }
        else {
            res += (s[i] - '0') + 1;
        }
    }
    if (chi2so(s) && s[0] != '1') {
        res--;
    }
    cout << res << endl;
}
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    tao();
    // cout << chay[9] << endl;
    int k = 1;
    cin >> k;
    while (k--) {
        solve();
    }
}