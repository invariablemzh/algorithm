#include <bits/stdc++.h>
using namespace std;

int n,V1,V2;
int f[1010][510];

int main(){
    scanf("%d%d%d",&V1,&V2,&n);
    for(int i = 1;i<=n;i++){
        int v1,v2;
        scanf("%d%d",&v1,&v2);
        for(int j = V1;j>=v1;j--){
            for(int k = V2-1;k>=v2;k--){
                f[j][k] = max(f[j][k],f[j-v1][k-v2]+1);
            }
        }
    }
    printf("%d ",f[V1][V2-1]);
    int k = 0;
    while(f[V1][V2-1]!=f[V1][k]) k++;
    printf("%d\n",V2-k);
    
}