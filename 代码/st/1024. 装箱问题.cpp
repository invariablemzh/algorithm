#include <bits/stdc++.h>
using namespace std;
const int N = 20010;

int n,m;
int f[N];

int main(){
    scanf("%d%d",&m,&n);
    for(int i = 1;i<=n;i++){
        int v;
        scanf("%d",&v);
        for(int j = m;j>=v;j--){
            f[j] = max(f[j],f[j-v]+v);
        }
    }
    printf("%d\n",m-f[m]);
}