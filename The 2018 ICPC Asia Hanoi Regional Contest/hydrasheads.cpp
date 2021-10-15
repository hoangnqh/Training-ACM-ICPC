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
const int MOD = 1000000007;
const int N = 2e5 + 5 ;
int a[N];
int b[N];
int delta(int x) {
    int temp = x;
    while (x % 4 != 0) {
        x++;
    }
    return x - temp;
}
int  solve1() {
    int h, t;
    cin >> h >> t;
    cout << h << " " << t << " ";
    int res = 0;
    if (h == 0 && t == 0) return 0;
    if (t == 0) {
        if (h % 2 == 0) {
            return h / 2;
        }
        return -1;
    }
    if (h % 2 == 0) {
        res += delta(t);
        t += delta(t);
        res += t / 2;
        h += t / 2;
        res += h / 2;
    }
    else {
        res += delta(t - 2);
        t += delta(t - 2);
        res += t / 2;
        h += t / 2;
        res += h / 2;
    }
    return res;

}
void solve() {

}
int32_t main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;
    while (1) {
        int h, t;
        cin >> h >> t;

        int res = 0;
        if (h == 0 && t == 0) break;
        if (t == 0) {
            if (h % 2 == 0) {
                cout << h / 2 << '\n';
                continue;
            }
            cout << -1 << '\n';
            continue;
        }
        if (h % 2 == 0) {
            res += delta(t);
            t += delta(t);
            res += t / 2;
            h += t / 2;
            res += h / 2;
            cout << res << '\n';
        }
        else {
            res += delta(t - 2);
            t += delta(t - 2);
            res += t / 2;
            h += t / 2;
            res += h / 2;
            cout << res << '\n';
        }

    }

    return 0;
}
