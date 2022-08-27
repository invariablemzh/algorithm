#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, INF = 0x3f3f3f3f;

int n,m;
int a[N],q[N],f[N];

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
    int hh = 0, tt = 0;
    for(int i = 1;i<=n;i++){
        if(q[hh]<i-m) hh++;
        f[i] = a[i] + f[q[hh]];
        while(hh<=tt&&f[q[tt]]>=f[i]) tt--;
        q[++tt] = i;
    }
    int res = INF;
    for(int i = n-m+1;i<=n;i++){
        res = min(res,f[i]);
    }
    printf("%d\n",res);
    return 0;
}