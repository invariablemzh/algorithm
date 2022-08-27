#include <bits/stdc++.h>
using namespace std;
const int N = 5010;
typedef long long ll;

int n,s;
ll st[N],sc[N],f[N];

int main(){
    memset(f,0x3f,sizeof(f));
    f[0] = 0;
    scanf("%d%d",&n,&s);
    for(int i = 1;i<=n;i++){
        scanf("%lld%lld",&st[i],&sc[i]);
        st[i] += st[i-1];
        sc[i] += sc[i-1];
    }
    for(int i = 1;i<=n;i++){
        for(int j = 0;j<i;j++){
            f[i] = min(f[i],f[j]+(ll)s*(sc[n]-sc[j])+st[i]*(sc[i]-sc[j]));
        }
    }
    printf("%lld\n",f[n]);
}