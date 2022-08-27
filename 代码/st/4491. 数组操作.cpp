#include <bits/stdc++.h>
using namespace std;
const int N = 110;

int n;
int a[N],s[N],f[N];

int main(){
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        s[i] += s[i-1] + a[i];
    }
    int ans = 0;
    for(int i = 1;i<=n;i++){
        ans = min(ans,s[i]);
    }
    printf("%d\n",s[n] - ans);
}