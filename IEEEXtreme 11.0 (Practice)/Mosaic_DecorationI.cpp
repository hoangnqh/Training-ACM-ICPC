#include <bits/stdc++.h>

using namespace std;

int n,b,p;

int main(){
    cin >> n >> b >> p;
    int black = 0;
    int pink = 0;
    for(int i = 0; i < n; i++){
        int x,y;
        cin >> x >> y;
        black += x;
        pink += y;
    }

    int ans = ((black+ 9)/10)*b + ((pink+9)/10)*p;

    cout << ans << endl;


}
