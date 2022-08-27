#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;

int n,k;
int a[N];

int main(){
    scanf("%d%d",&n,&k);
    int minus = 0, cnt = 0;
    for(int i = 1;i<=n;i++) scanf("%d",&a[i]);
    sort(a+1,a+n+1);
    while(k--){
        while(a[cnt+1] - minus == 0 ) cnt++;
        if(cnt+1>n) {
            puts("0");
            continue;
        }
        printf("%d\n",a[++cnt] - minus);
        minus += a[cnt] - minus;
    }
}