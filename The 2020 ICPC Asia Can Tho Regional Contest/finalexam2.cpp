#include<bits/stdc++.h>
using namespace std;

int n;
char a[1005];

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }

    int res = 0;
    for(int i = 2; i <= n; i++){
        if(a[i - 1] == a[i]) res += 1;
    }

    cout << res;
}
