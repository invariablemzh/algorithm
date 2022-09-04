#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 2e5 + 10;
int a[N], b[N];

void solve(){
    int n; cin >> n;
    bool flag = true;
    int min_b = 1e9, pos = 0;
    for(int i = 1;i<=n;i++) {
        cin >> a[i];
    }
    for(int i = 1;i<=n;i++) {
        cin >> b[i];
        if(min_b > b[i]){
            min_b = b[i];
            pos = i;
        }
    }
    for(int i = 1;i<=n;i++){
        if(a[i]>b[i]) flag = false;
    }
    min_b ++;
    for(int i = pos - 1;i>=1;i--){
        a[i] = max(a[i],min_b);
        if(a[i]<b[i]) flag = false;
        min_b = b[i] + 1;
    }
    for(int i = n;i>=pos;i--){
        a[i] = max(a[i],min_b);
        if(a[i]<b[i]) flag = false;
        min_b = b[i] + 1;
    }

    if(flag) cout << "YES" <<'\n';
    else cout << "NO" << '\n';
}

int main(){
    FAST
    int T = 1;
    cin >> T;
    while(T--) solve();
    
}