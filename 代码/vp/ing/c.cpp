#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

typedef long long ll;
const int N = 1e6 + 10;
int b[N];
int a[N];

void solve(){
    int n; cin >> n;
    for(int i = 1;i<=n;i++) cin >> b[i];
    for(int i = 1;i<=n;i++) a[i] = b[i];
    ll res1 = 0;    //2是max
    if(b[1]>=b[2]) {
        res1 += b[1] - b[2] + 1;
        b[2] += b[1] - b[2] + 1;
    }
    bool minn = true;
    for(int i = 3;i<=n;i++){
        if(minn&&b[i] >= b[i-1]){
            res1 += b[i] - b[i-1] + 1;
            b[i] -= b[i] - b[i-1] + 1;
            
        }
        else if(!minn&&b[i] <= b[i-1]){
            res1 += b[i-1] - b[i] + 1;
            b[i] += b[i-1] - b[i] + 1;
            
        }
        minn = !minn;
    }
    // for(int i = 1;i<=n;i++) cout << b[i] << ' ';
    // cout << endl;
    for(int i = 1;i<=n;i++) b[i] = a[i];
    ll res2 = 0;
    if(b[1]<=b[2]) {
        res2 += b[2] - b[1] + 1;
        b[2] -= b[2] - b[1] + 1;
    }
    minn = false;
    for(int i = 3;i<=n;i++){
        if(minn&&b[i] >= b[i-1]){
            res2 += b[i] - b[i-1] + 1;
            b[i] -= b[i] - b[i-1] + 1;
            
        }
        else if(!minn&&b[i] <= b[i-1]){
            res2 += b[i-1] - b[i] + 1;
            b[i] += b[i-1] - b[i] + 1;
            
        }
        minn = !minn;
    }
    // for(int i = 1;i<=n;i++) cout << b[i] << ' ';
    // cout << endl;
    cout << min(res1,res2)<<endl;
}

int main(){
    FAST
    int T; cin >> T;
    while(T--) solve();
}