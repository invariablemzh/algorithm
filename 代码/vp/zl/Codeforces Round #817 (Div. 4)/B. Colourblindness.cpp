#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 110;
char s[5][N];

void solve(){
    int n; cin >> n;
    for(int i = 1;i<=2;i++){
        for(int j = 1;j<=n;j++){
            cin >> s[i][j];
            if(s[i][j]=='G') s[i][j] = 'B';
        }
    }
    bool flag = true;
    for(int i = 1;i<=n;i++){
        if(s[1][i] != s[2][i]) flag = false;
    }
    if(!flag) cout << "NO" << '\n';
    else cout << "YES" << '\n';
}

int main(){
    FAST
    int T; cin >> T;
    while(T--) solve();
}