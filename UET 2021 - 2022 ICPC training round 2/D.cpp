#include<bits/stdc++.h>
using namespace std;

#define int long long
#define x dfgasdgd
#define y gasdg
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


void solve(){
    int x = 0, y = 0;
    int a, b;
    int l = 0, r = 1000000;
    cout << 0 << " " << 0 << endl;
    cin >> a;
    if(a == 0) return;
    cout << 1 << " " << 0 << endl;
    cin >> b;
    if(b == 0) return;
    int val;
    for(int i = 0; i <= 5; i++){
        for(int j = 0; j <= 5; j++){
            cout << i << " " << j << endl;
            cin >> val;
            if(val == 0) return;
        }
    }
    x = (a - b + 1) / 2;
    y = sqrt(a - x * x);
    cout << x << " " << y << endl;
    cin >> val;
    if(val == 0) return;

    cout << 2 << " " << 0 << endl;
    cin >> b;
    if(b == 0) return;
    x = (a - b + 4) / 4;
    y = sqrt(a - x * x);
    cout << x << " " << y << endl;
    cin >> val;
    if(val == 0) return;

    cout << 0 << " " << 1 << endl;
    cin >> b;
    if(b == 0) return;
    y = (a - b + 1) / 2;
    x = sqrt(a - y * y);
    cout << x << " " << y << endl;
    cin >> val;
    if(val == 0) return;

    cout << 0 << " " << 2 << endl;
    cin >> b;
    if(b == 0) return;
    y = (a - b + 4) / 4;
    x = sqrt(a - y * y);
    cout << x << " " << y << endl;
    cin >> val;
    if(val == 0) return;

    while(val) {}

}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T; while(T--)
    solve();
}
