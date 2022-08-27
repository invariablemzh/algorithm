#include <bits/stdc++.h>
using namespace std;
const int N = 110, M = 25010;


int n;
int a[N];
bool f[M];

void solve(){
    memset(f,false,sizeof(f));
    scanf("%d",&n);
    for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    f[0] = true;
    int res = 0;
    for(int i = 1;i<=n;i++){
        if(!f[a[i]]) res++;
        for(int j = a[i];j<=a[n];j++){
            f[j] |= f[j-a[i]];
        }
    }
    printf("%d\n",res);
}


int main(){
    int T; scanf("%d",&T);
    while(T--) solve();
}