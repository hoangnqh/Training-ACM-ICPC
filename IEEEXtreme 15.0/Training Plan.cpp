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
typedef vector<int> VI;
typedef vector<VI > VII;
typedef vector<VII > VIII;

int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

const int INF = 1e18;
const int MOD = 1e9 + 7;
const int N = 1e3 + 5;

int a[N][N];
int M, X, Y, K;
VIII f;

void solve(){
    cin >> M >> X >> Y >> K;
    for(int i = 1; i <= M; i++){
        for(int j = 1; j <= X; j++){
            cin >> a[i][j];
        }
    }

    f = VIII(X + 5, VII(Y + 5, VI(K + 5, -1)));

    f[0][0][0] = 0;
    for(int w = 1; w <= M; w++){
        for(int i = 1; i <= X; i++)
        for(int j = 0; j <= Y; j++)
        for(int t = 0; t <= K; t++)
            f[i][j][t] = -1;

        for(int i = 1; i <= X; i++){
            for(int j = 0; j <= Y; j++){
                // khong lay
                for(int t = 0; t <= K; t++){
                    if(f[i - 1][j][t] != -1){
                        f[i][j][0] = max(f[i][j][0], f[i - 1][j][t]);
                    }
                }

                // lay
                if(j == 0) continue;
                for(int t = 1; t <= K; t++){
                    if(f[i - 1][j - 1][t - 1] != -1){
                        f[i][j][t] = f[i - 1][j - 1][t - 1] + a[w][i];
                    }
                }
            }
        }
        for(int t = 0; t <= K; t++){
            f[0][0][t] = f[X][Y][t];
        }
    }

    int res = -1;
    for(int t = 0; t <= K; t++){
        res = max(res, f[X][Y][t]);
    }
    if(res == -1){
        cout << "IMPOSSIBLE" << '\n';
    }
    else cout << res << '\n';

}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    int T; cin >> T; while(T--)
    solve();
}
/**
4
1 7 5 2
1 2 3 3 1 1 9


1 7 1 2
1 1 1 7 1 1 1


1 7 6 2
1 1 1 1 1 1 1


1 7 5 2
1 1 1 1 100 100 1
*/
