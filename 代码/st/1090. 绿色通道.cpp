#include <bits/stdc++.h>
using namespace std;
const int N = 5e4+10, INF = 0x3f3f3f3f;

int n,t;
int a[N],s[N],q[N],f[N];

bool check(int x){
    f[0] = 0;
    int hh = 0, tt = 0;
    for(int i = 1;i<=n;i++){
        if(hh<=tt&&q[hh]<i-x-1) hh++;
        f[i] = f[q[hh]] + a[i];
        while(hh<=tt&&f[q[tt]]>=f[i]) tt--;
        q[++tt] = i;
    }
    int res = INF;
    for(int i = n - x;i<=n;i++) res = min(res,f[i]);
    return res<=t;
}

int main(){
    scanf("%d%d",&n,&t);
    for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
    int l = 0, r = n;
    while(l<r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    printf("%d\n",r);
}