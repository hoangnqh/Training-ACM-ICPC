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
const int N = 1e2 + 5;

int r, c, q;

char a[N][N];

void solve(){
    cin >> r >> c >> q;
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            cin >> a[i][j];
        }
    }

    while(q--){
        string s;
        cin >> s;
        int KT = 0;
        for(int i = 1; i <= r; i++){
            if(KT) break;
            for(int j = 1; j <= c; j++){
                if(KT) break;
                if(a[i][j] != s[0]) continue;
                int i1, j1, i2, j2;

                /// Cheo chinh duoi len tren
                i1 = i, j1 = j;
                i2 = i - s.size() + 1, j2 = j - s.size() + 1;
                if(i2 >= 1 && j2 >= 1){
                    int val = 0;
                    for(; i1 >= i2; i1--, j1--){
                        int su = i - i1;
                        if(s[su] != a[i1][j1]) break;
                        val += 1;
                    }
                    if(val == s.size()){
                        KT = 1;
                        cout << i - 1 << " " << j - 1 << " " << i2 - 1 << " " << j2 - 1 << '\n';
                        break;
                    }
                }

                /// Phai sang trai
                i1 = i, j1 = j;
                i2 = i, j2 = j - s.size() + 1;
                if(j2 >= 1){
                    int val = 0;
                    for(; j1 >= j2; j1--){
                        int su = j - j1;
                        if(s[su] != a[i1][j1]) break;
                        val += 1;
                    }
                    if(val == s.size()){
                        KT = 1;
                        cout << i - 1 << " " << j - 1 << " " << i2 - 1 << " " << j2 - 1 << '\n';
                        break;
                    }
                }

                /// Duoi len tren
                i1 = i, j1 = j;
                i2 = i - s.size() + 1, j2 = j;
                if(i2 >= 1){
                    int val = 0;
                    for(; i1 >= i2; i1--){
                        int su = i - i1;
                        if(s[su] != a[i1][j1]) break;
                        val += 1;
                    }
                    if(val == s.size()){
                        KT = 1;
                        cout << i - 1 << " " << j - 1 << " " << i2 - 1 << " " << j2 - 1 << '\n';
                        break;
                    }
                }


                /// Trai sang phai
                i1 = i, j1 = j;
                i2 = i, j2 = j + s.size() - 1;
                if(j2 <= c){
                    int val = 0;
                    for(; j1 <= j2; j1++){
                        int su = j1 - j;
                        if(s[su] != a[i1][j1]) break;
                        val += 1;
                    }
                    if(val == s.size()){
                        KT = 1;
                        cout << i - 1 << " " << j - 1 << " " << i2 - 1 << " " << j2 - 1 << '\n';
                        break;
                    }
                }



                /// Tren xuong duoi
                i1 = i, j1 = j;
                i2 = i + s.size() - 1, j2 = j;
                if(i2 <= r){
                    int val = 0;
                    for(; i1 <= i2; i1++){
                        int su = i1 - i;
                        if(s[su] != a[i1][j1]) break;
                        val += 1;
                    }
                    if(val == s.size()){
                        KT = 1;
                        cout << i - 1 << " " << j - 1 << " " << i2 - 1 << " " << j2 - 1 << '\n';
                        break;
                    }
                }



                /// Cheo chinh tren xuong duoi
                i1 = i, j1 = j;
                i2 = i + s.size() - 1, j2 = j + s.size() - 1;
                if(i2 <= r && j2 <= c){
                    int val = 0;
                    for(; i1 <= i2; i1++, j1++){
                        int su = i1 - i;
                        if(s[su] != a[i1][j1]) break;
                        val += 1;
                    }
                    if(val == s.size()){
                        KT = 1;
                        cout << i - 1 << " " << j - 1 << " " << i2 - 1 << " " << j2 - 1 << '\n';
                        break;
                    }
                }


                /// Cheo phu tren xuong duoi
                i1 = i, j1 = j;
                i2 = i + s.size() - 1, j2 = j - s.size() + 1;
                if(i2 <= r && j2 >= 1){
                    int val = 0;
                    for(; i1 <= i2; i1++, j1--){
                        int su = i1 - i;
                        if(s[su] != a[i1][j1]) break;
                        val += 1;
                    }
                    if(val == s.size()){
                        KT = 1;
                        cout << i - 1 << " " << j - 1 << " " << i2 - 1 << " " << j2 - 1 << '\n';
                        break;
                    }
                }

                /// Cheo phu duoi len tren
                i1 = i, j1 = j;
                i2 = i - s.size() + 1, j2 = j + s.size() - 1;
                if(i2 >= 1 && j2 <= c){
                    int val = 0;
                    for(; i1 >= i2; i1--, j1++){
                        int su = i - i1;
                        if(s[su] != a[i1][j1]) break;
                        val += 1;
                    }
                    if(val == s.size()){
                        KT = 1;
                        cout << i - 1 << " " << j - 1 << " " << i2 - 1 << " " << j2 - 1 << '\n';
                        break;
                    }
                }
            }
        }
        if(KT == 0){
            cout << -1 << '\n';
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    //int T; cin >> T; while(T--)
    solve();
}
/**
5 11 2
ietextremef
aiehextremi
eaieiextrer
meaierextrs
esecondextt
xrmf
fmrx
*/
