#include<bits/stdc++.h>
using namespace std;

#define int long long

#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define ld long double
#define cc cout<<"CC"<<endl;

typedef pair<int, int> II;
typedef pair<int, II> III;

/// 4 directions
int dx[] = {0, 1, 0, -1};
int dy[] = {1, 0, -1, 0};

/// Default long long max => 1e18
const int INF = 1e18;

/// Default MOD => 1e9 + 7
const int MOD = 1e9 + 7;

/// Input limit
const int N = 1e5 + 5;

int n;

void query(int u, int v){
    cout << "QUERY" << " " << u << " " << v << endl;
    fflush(stdout);
}

void answer(int val){
    cout << "YES" << " " << val << endl;
    fflush(stdout);
}

void solve(){
    cin >> n;
    if(n % 2 == 1){
        cout << "NO";
        return;
    }
    int val = 500000000;
    query(0, val - 1);
    int x; cin >> x;
    int check = 0;
    if(x == n / 2){
        answer(0);
        return;
    }

    if(x < n / 2) check = 0;
    else check = 1;
    //int check = 0;

    int l = 0, r = val - 1;
    while(l <= r){
        int m = (l + r) / 2;
        query(m, m + val - 1);
        int x;
        cin >> x;
        if(x == n / 2){
            answer(m);
            return;
        }
        if(check){
            if(x < n / 2){
                r = m - 1;
            }
            else l = m + 1;
        }
        else{
            if(x < n / 2){
                l = m + 1;
            }
            else r = m - 1;
        }
        if(l == r){
            answer(l);
            return;
        }
    }

    cout << "NO";
}

int32_t main(){
	//freopen("C:\\Users\\nqhho\\Desktop\\CP\\test.txt", "r", stdin);
	ios_base::sync_with_stdio(false); cin.tie(0);
	int T = 1;
	//cin >> T;
	while(T--){solve();}
}
