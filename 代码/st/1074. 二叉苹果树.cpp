#include <bits/stdc++.h>
using namespace std;
const int N = 110, M = N * 2;

int n,m;
int h[N],e[M],ne[M],w[M],idx;
int f[N][N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u,int fa){
    for(int i = h[u];~i;i=ne[i]){
        int son = e[i];
        if(son==fa) continue;
        dfs(son,u);
        for(int j = m;j>=0;j--){
            for(int k = 0;k+1<=j;k++){
                f[u][j] = max(f[u][j],f[u][j-k-1] + f[son][k] + w[i]);  //f[u][j-k-1]：1是算上w[i]的那根树枝
            }
        }
    }
}

int main(){
    memset(h,-1,sizeof(h));
    scanf("%d%d",&n,&m);
    for(int i = 0;i<n-1;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c), add(b,a,c);
    }
    dfs(1,-1);
    printf("%d\n",f[1][m]);
}