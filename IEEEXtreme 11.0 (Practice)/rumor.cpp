#include <bits/stdc++.h>

using namespace std;



int main(){

    int q;
    cin >> q;
    while(q--){
        long long a ,b;
        cin >> a >> b;
        int cnt_a = 0;
        int cnt_b = 0;
        while(a != b){
            if(a > b){
                a /= 2;
                cnt_a ++;
            }else if(a < b){
                b /= 2;
                cnt_b ++;
            }
        }

        cout << cnt_a + cnt_b << endl;


    }


}
