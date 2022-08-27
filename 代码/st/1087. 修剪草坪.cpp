#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
typedef long long ll;

int n,k;
ll s[N],f[N];
int q[N];

ll g(int i){
    if(!i) return 0;
    else return f[i-1] - s[i];
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i = 1;i<=n;i++){
        scanf("%lld",&s[i]);
        s[i] += s[i-1];
    }
    int hh = 0, tt = 0;
    for(int i = 1;i<=n;i++){
        if(q[hh]<i-k) hh++;
        f[i] = max(f[i-1],g(q[hh])+s[i]);
        while(hh<=tt&&g(q[tt])<=g(i)) tt--;
        q[++tt] = i;
    }
    printf("%lld\n",f[n]);
}