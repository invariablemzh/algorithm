#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 1e5 + 10;
int a[N], sum[N], minu[N];


void solve(){
    int n,q;
    cin >> n >> q;
    for(int i = 1;i<=n;i++) cin >> a[i];
    bool flag = false;
    int maxx = 0, pos = 0;
    for(int i = 2;i<=n;i++){
        if(a[i]<a[i-1]&&maxx<a[i]) {
            maxx = a[i];
            pos = i;
            if(flag) sum[i] = sum[i-1];
            else sum[i] = sum[i-1] + 1;
            flag = true;
        }
        else if(a[i]<a[i-1]){
            minu[i] = minu[i-1];
            for(int j = pos;j<=i;j++) minu[j]++;
            pos = i;
            if(flag) {
                sum[i] = sum[i-1];
                minu[i] = minu[i-1];
            }    
            sum[i] = sum[i-1] + 1;
            flag = true;
        }
        else {
            flag = false;
            sum[i] = sum[i-1];
            minu[i] = minu[i-1];
        }
    }
    for(int i = 1;i<=n;i++){
        cout << sum[i] << ' ';
    }
    puts("");

    for(int i = 1;i<=n;i++){
        cout << minu[i] << ' ';
    }
    puts("");

    while(q--){
        int l,r;
        cin >> l >> r;
        cout << (sum[r] - minu[r]) - (sum[l-1] - minu[l-1])<< endl;
    }
}

int main(){
    FAST
    int T; cin >> T;
    while(T--) solve();
}