#include<bits/stdc++.h>
using namespace std;

#define int long long

int p[100], s[100], a[100];
int n, k;

void solve(){
    cin >> n >> k;

    int pos = 0;
    for(int i = 1; i <= 38; i++){
        if(s[i] > n){
            pos = i;
            break;
        }
    }

    //cout << pos << endl;

    int res = 1;
    int l = 1, r = 4e18;
    while(l <= r){
        int m = (l + r) / 2;
        int cnt = k;

        // cover full
        for(int i = 0; i < pos; i++){
            int l1 = 1, r1 = a[i];
            int l2 = a[i] * 2, r2 = a[i] * 2 + p[i] / 2 - 1;
            //cout << l1 << " " << r1 << " " << l2 << " " << r2 << endl;
            if(r1 >= l1){
                if(m >= r1){
                    cnt -= r1 - l1 + 1;
                }
                else{
                    if(m >= l1){
                        cnt -= m - l1 + 1;
                    }
                }
            }
            if(r2 >= l2){
                if(m >= r2){
                    cnt -= r2 - l2 + 1;
                }
                else{
                    if(m >= l2){
                        cnt -= m - l2 + 1;
                    }
                }
            }
        }

        // cover part
        int val = n - s[pos - 1];
        int l1 = a[pos] - val / 2 + 1 - val % 2, r1 = a[pos];
        int l2 = a[pos] * 2, r2 = a[pos] * 2 + val / 2 - 1;
        //cout << val << endl;
        //cout << l1 << " " << r1 << "       " << l2 << " " << r2 << endl;
        if(r1 >= l1){
            if(m >= r1){
                cnt -= r1 - l1 + 1;
            }
            else{
                if(m >= l1){
                    cnt -= m - l1 + 1;
                }
            }
        }
        if(r2 >= l2){
            if(m >= r2){
                cnt -= r2 - l2 + 1;
            }
            else{
                if(m >= l2){
                    cnt -= m - l2 + 1;
                }
            }
        }
        //cout << m << " " << cnt << endl;

        // caculate
        if(cnt <= 0){
            res = m;
            r = m - 1;
        }
        else l = m + 1;
    }
    cout << res << '\n';
}

int32_t main(){
    ios_base::sync_with_stdio(0); cin.tie(0);

    p[0] = 1;
    for(int i = 1; i <= 38; i++){
        p[i] = p[i - 1] * 3;
        //cout << p3[i] << endl;
    }
    s[0] = 1;
    for(int i = 1; i <= 38; i++){
        s[i] = s[i - 1] + p[i];
        //cout << s[i] << endl;
    }
    a[0] = 1;
    for(int i = 1; i <= 38; i++){
        a[i] = a[i - 1] + p[i - 1];
        //cout << a[i] << endl;
    }
    int t;
    cin >> t;
    while(t--) solve();


}
