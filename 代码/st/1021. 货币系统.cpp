#include <bits/stdc++.h>
using namespace std;
const int N = 3010;
typedef long long ll;

int n,m;
ll f[N];

int main(){
    scanf("%d%d",&n,&m);
    f[0] = 1;
    for(int i = 1;i<=n;i++){
        int v; scanf("%d",&v);
        for(int j = v;j<=m;j++){
            f[j] += f[j-v];
        }
    }
    printf("%lld\n",f[m]);
}