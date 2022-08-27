#include <bits/stdc++.h>
using namespace std;
const int N = 10010, M = N * 2, INF = 0x3f3f3f3f;

int n;
int h[N],e[M],ne[M],w[M],idx;
int d1[N],d2[N], up[N], p[N];
bool is_leaf[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dfs_d(int u,int fa){
    d1[u] = d2[u] = -INF;
    for(int i = h[u];~i;i=ne[i]){
        int j = e[i];
        if(j==fa) continue;
        int d = dfs_d(j,u) + w[i];
        if(d>d1[u]) {
            d2[u] = d1[u], d1[u] = d;
            p[u] = j;
        }
        else if(d>d2[u]) d2[u] = d;
    }
    if(d1[u]==-INF){
        d1[u] = d2[u] = 0;
        is_leaf[u] = true;
    }
    return d1[u];
}

void dfs_u(int u,int fa){
    for(int i = h[u];~i;i=ne[i]){
        int j = e[i];
        if(j==fa) continue;
        if(p[u]==j) up[j] = max(up[u],d2[u]) + w[i];
        else up[j] = max(up[u],d1[u]) + w[i];
        dfs_u(j,u);
    }
}

int main(){
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    for(int i = 0;i<n-1;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c), add(b,a,c);
    }
    dfs_d(1,-1);
    dfs_u(1,-1);
    int res = d1[1];
    for(int i = 2;i<=n;i++){
        if(is_leaf[i]) res = min(res,up[i]);
        else res = min(res,max(d1[i],up[i]));
    }
    printf("%d\n",res);
    return 0;
}