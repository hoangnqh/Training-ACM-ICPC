#include <bits/stdc++.h>

using namespace std;

int t;

int a,b,c1,c2;

int k;

struct Point{
    int x,y;
};

Point point[10];

int f1(int i){
    return a*point[i].x + b*point[i].y - c1;
}

int f2(int i){
    return a*point[i].x + b*point[i].y - c2;
}

bool check(){


    for(int i = 0; i < k; i++){
        int j = (i + 1)%k;

        int p1 = f1(i);
        int p2 = f1(j);
        int p3 = f2(i);
        int p4 = f2(j);

        if(p1*p2 < 0 || p3*p4 < 0){
            return true;
        }

        if(p1 == 0 && p4 == 0 || p2 == 0 && p3 == 0){
            return true;
        }

        if(p1*p3 < 0){
            return true;
        }

    }

    return false;
}


int main(){
    cin >> t;
    while(t--){
        cin >> a >> b >> c1 >> c2;
        cin >> k;
        for(int i = 0; i <k ;i++){
            cin >> point[i].x >> point[i].y;
        }

        if(check()){
            cout << "YES\n";
        }else{
            cout << "NO\n";
        }

    }
    return 0;
}
