#include<bits/stdc++.h>
using namespace std;

int r, c;

int x[10][10];
vector<int> a[10], b[10];
int res = 0;

int checkCol(){
    for(int j = 1; j <= c; j++){
        vector<int> temp;
        int cnt = 0;
        for(int i = 1; i <= r; i++){
            if(x[i][j]){
                cnt += 1;
            }
            else{
                if(cnt != 0){
                    temp.push_back(cnt);
                    cnt = 0;
                }
            }
        }
        if(cnt != 0){
            temp.push_back(cnt);
        }

        if(temp != b[j]) return 0;
    }

    return 1;
}

int checkRow(int i){
    vector<int> temp;
    int cnt = 0;
    for(int j = 1; j <= c; j++){
        if(x[i][j]){
            cnt += 1;
        }
        else{
            if(cnt != 0){
                temp.push_back(cnt);
                cnt = 0;
            }
        }
    }
    if(cnt != 0){
        temp.push_back(cnt);
    }

    if(temp != a[i]) return 0;
    else return 1;
}

void ql(int hang, int cot){
    if(hang > r){
        if(checkCol()) res += 1;
        return;
    }
    if(cot > c){
        if(checkRow(hang)) ql(hang + 1, 1);
        return;
    }
    ql(hang, cot + 1);
    x[hang][cot] = 1;
    ql(hang, cot + 1);
    x[hang][cot] = 0;
}

int main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    cin >> r >> c;
    for(int i = 1; i <= r; i++){
        int k; cin >> k;
        for(int j = 1; j <= k; j++){
            int x; cin >> x;
            a[i].push_back(x);
        }
    }

    for(int i = 1; i <= c; i++){
        int k; cin >> k;
        for(int j = 1; j <= k; j++){
            int x; cin >> x;
            b[i].push_back(x);
        }
    }

    ql(1, 1);

    cout << res << '\n';
}
