#include <bits/stdc++.h>
using namespace std;
const int N = 1010;

int n,m;
int f[N];

int main(){
    scanf("%d%d",&m,&n);
    for(int i = 1;i<=n;i++){
        int v,w;
        scanf("%d%d",&v,&w);
        for(int j = m;j>=v;j--){
            f[j] = max(f[j],f[j-v]+w);
        }
    }
    printf("%d\n",f[m]);
}