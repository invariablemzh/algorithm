#include <bits/stdc++.h>
using namespace std;
const int N = 10010;

int n,m;
int f[N];

int main(){
    scanf("%d%d",&n,&m);
    f[0] = 1;
    for(int i = 1;i<=n;i++){
        int v; scanf("%d",&v);
        for(int j = m;j>=v;j--){
            f[j] += f[j-v];
        }
    }
    printf("%d\n",f[m]);
}