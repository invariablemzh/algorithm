#include <bits/stdc++.h>
using namespace std;
const int N = 300010, INF = 0x3f3f3f3f;

int n,m;
int q[N],s[N];

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++) scanf("%d",&s[i]), s[i] += s[i-1];
    int hh = 0, tt = 0;
    int res = -INF;
    for(int i = 1;i<=n;i++){
        if(q[hh]<i-m) hh ++;
        res = max(res,s[i] - s[q[hh]]);
        while(hh<=tt&&s[i]<=s[q[tt]]) tt--;
        q[++tt] = i; 
    }
    printf("%d\n",res);
}