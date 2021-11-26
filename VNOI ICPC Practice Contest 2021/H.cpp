#include <bits/stdc++.h>

using namespace std;

int n,m,d;

int main(){
    cin >> n >> m >> d;
    map<string,int> mp;


    for(int i = 0; i <= n; i++){
       string c;
       getline(cin,c);
       mp[c] ++;
    }


    for(int i = 0; i <= m-1; i++){
        string c;
        getline(cin,c);

        if(mp[c] > 0){
            cout <<"BAD"<<endl;
        }else{
            cout <<"GOOD"<<endl;
        }
    }


    return 0;

}
