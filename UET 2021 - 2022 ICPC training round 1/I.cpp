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
    int a, b;
    char trash;
    cin >> a >> trash >> b;
    for(int aWin = 6; aWin <= 20; aWin++){
        if(a < 4 * aWin) break;
        int kt = 0;
        if(aWin != 6) kt = aWin - 2;
        for(int bWin = aWin - 2; bWin >= kt; bWin--){
            if(b < 4 * bWin) continue;
            int x = a - 4 * aWin;
            int y = b - 4 * bWin;

            if(x <= 2 * bWin && y <= 2 * aWin){
                cout << "YES" << '\n';
                return;
            }
            if(x >= y && bWin){
                x -= 2;
                int val = max(0LL, min(x, y));
                x -= val, y -= val;
                if(x <= 2 * bWin - 2 && y <= 2 * aWin){
                    cout << "YES" << '\n';
                    return;
                }
            }
            else if(x < y){
                y -= 2;
                int val = max(0LL, min(x, y));
                x -= val, y -= val;
                if(x <= 2 * bWin && y <= 2 * aWin - 2){
                    cout << "YES" << '\n';
                    return;
                }
            }
        }
    }
    cout << "NO" << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T; while(T--)
    solve();
}
