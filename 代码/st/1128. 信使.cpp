#include <bits/stdc++.h>
using namespace std;
const int N = 110, INF = 0x3f3f3f3f;

int n,m;
int d[N][N];

void floyd(){
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                d[i][j] = min(d[i][k] + d[k][j], d[i][j]);
            }
        }
    }
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i==j) d[i][j] = 0;
            else d[i][j] = INF;
        }
    }
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        d[a][b] = d[b][a]= min(d[a][b],c);
    }
    floyd();
    int res = 0;
    for(int i = 1;i<=n;i++){
        res = max(res,d[1][i]);
    }
    if(res==INF) puts("-1");
    else printf("%d\n",res);
}