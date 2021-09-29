#include <bits/stdc++.h>

using namespace std;

int main(){
    int a,b,c,n;
    cin >> a >> b >> c >> n;
    if(a && b && c && (a+b+c) >= n){
        cout << "YES\n";
    }else{
        cout << "NO\n";
    }
    return 0;
}
