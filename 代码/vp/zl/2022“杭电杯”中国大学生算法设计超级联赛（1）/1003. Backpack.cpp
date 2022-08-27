#include <bits/stdc++.h>
using namespace std;
const int N = 1050;

int n,m;
bitset<N> f[N], g[N];

void solve(){
    for(int j = 0;j<1024;j++) f[j].reset();
    scanf("%d%d",&n,&m);
    f[0][0] = 1;
    for(int i = 1;i<=n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        for(int j = 0;j<1024;j++){
            g[j] = f[j];
            g[j] <<= x;
        }
        for(int j = 0;j<1024;j++){
            f[j] |= g[j ^ y];
        }
    }
    int ans = -1;
    for(int j = 0;j<1024;j++){
        if(f[j][m]){
            ans = max(ans,j);
        }
    }
    printf("%d\n",ans);
}

int main(){
    int T; scanf("%d",&T);
    while(T--) solve();
}