#include <bits/stdc++.h>
using namespace std;
const int N = 300010;
typedef long long ll;

int n,s;
ll t[N],c[N],f[N];
int q[N];

int main(){
    scanf("%d%d",&n,&s);
    for(int i = 1;i<=n;i++){
        scanf("%lld%lld",&t[i],&c[i]);
        t[i] += t[i-1];
        c[i] += c[i-1];
    }
    int hh = 0, tt = 0;
    for(int i = 1;i<=n;i++){
        while(hh<tt&&f[q[hh+1]] - f[q[hh]] <= (t[i] + s) * (c[q[hh+1]]-c[q[hh]])) hh++;
        f[i] = t[i] * c[i] + s * c[n] + f[q[hh]] - c[q[hh]] * (s + t[i]);
        while(hh<tt&&(f[q[tt]]-f[q[tt-1]]) * (c[i] - c[q[tt-1]]) >= (f[i]-f[q[tt-1]]) * (c[q[tt]] - c[q[tt-1]])) tt--;
        q[++tt] = i;
    }
    printf("%lld\n",f[n]);
}