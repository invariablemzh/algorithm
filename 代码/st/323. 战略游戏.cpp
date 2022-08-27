#include <bits/stdc++.h>
using namespace std;
const int N = 1510, M = 15010 * 2;

int n,root;
int h[N],e[M],ne[M],w[M],idx;
int f[N][2];
bool st[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u){
    f[u][1] = 1;
    for(int i = h[u];~i;i=ne[i]){
        int j =  e[i];
        dfs(j);
        f[u][0] += f[j][1];
        f[u][1] += min(f[j][0],f[j][1]);
    }
}

int main(){
    while(~scanf("%d",&n)){
        memset(h,-1,sizeof(h));
        memset(st,false,sizeof(st));
        memset(f,0,sizeof(f));
        idx = 0;
        for(int i = 0;i<n;i++){
            int id,cnt;
            scanf("%d:(%d)",&id,&cnt);
            while(cnt--){
                int x; scanf("%d",&x);
                add(id,x);
                st[x] = true;
            }
        }
        root = 0;
        while(st[root]) root++;
        dfs(root);
        printf("%d\n",min(f[root][1],f[root][0]));
    }
}