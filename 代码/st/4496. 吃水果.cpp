#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2010;
const ll mod = 998244353;

int n,m,k;
ll f[N][N];

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i<=n;i++) f[i][0] = m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=k;j++){
            f[i][j] = (f[i-1][j] + (f[i-1][j-1] * (m-1)) % mod ) % mod;
        }
    }
    // for(int i = 1;i<=n;i++){
    //     for(int j = 1;j<=k;j++){
    //         cout<<f[i][j]<<" ";
    //     }
    //     puts("");
    // }
    printf("%lld\n",f[n][k]);
}

