#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10, M = 4e5 + 10;

int n,m,res;
int h[N],e[M],ne[M],idx;
bool st[N],vis[N],flag;
int d[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void check(int x){
    vis[x] = true;
    st[x] = false;
    for(int i = h[x];~i;i=ne[i]){
        int j = e[i];
        if(!vis[j]) check(j);
    }
}

void dfs(int x,int fa){
    if(vis[x]){
        flag = true;
        return;
    }
    vis[x] = true;
    for(int i = h[x];~i;i=ne[i]){
        int j = e[i];
        if(j!=fa) dfs(j,x);
    }
}

int main(){
    memset(h,-1,sizeof(h));
    memset(st,true,sizeof(st));
    scanf("%d%d",&n,&m);
    while(m--){
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b), add(b,a);
        d[a]++, d[b]++;
    }
    for(int i = 1;i<=n;i++){
        if(d[i]!=2) check(i);
    }
    memset(vis,false,sizeof(vis));
    for(int i = 1;i<=n;i++){
        if(st[i]&&!vis[i]) {
            flag = false;
            dfs(i,-1);
            if(flag) res++;
        }
    }
    printf("%d\n",res);
}