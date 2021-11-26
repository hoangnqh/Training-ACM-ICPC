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



void solve(){
    int x1 = 1, y1 = 1, x2 = 1000000000, y2 = 1000000000;
    cout << "? " << x1 << " " << y1 << " " << x2 << " " << y2 << endl;
    int area;
    cin >> area;
    // x1
    int L = x1, R = x2;
    while(L <= R){
        int m = (L + R) / 2;
        cout << "? " << m << " " << y1 << " " << x2 << " " << y2 << endl;
        int s;
        cin >> s;
        if(s != area){
            R = m - 1;
        }
        else{
            L = m + 1;
            x1 = m;
        }
    }

    L = y1, R = y2;
    while(L <= R){
        int m = (L + R) / 2;
        cout << "? " << x1 << " " << m << " " << x2 << " " << y2 << endl;
        int s;
        cin >> s;
        if(s != area){
            R = m - 1;
        }
        else{
            L = m + 1;
            y1 = m;
        }
    }
    int val1;
    if(x1 + 1 <= x2){
        cout << "? " << x1 + 1 << " " << y1 << " " << x2 << " " << y2 << endl;
        cin >> val1;
    }
    else val1 = 0;
    int dai = area - val1;

    int val2;
    if(y1 + 1 <= y2){
        cout << "? " << x1 << " " << y1 + 1 << " " << x2 << " " << y2 << endl;
        cin >> val2;
    }
    else val2 = 0;
    int rong = area - val2;
    cout << "! " << x1 << " " << y1 << " " << x1 + rong - 1 <<  " " << y1 + dai - 1 << endl;

}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
