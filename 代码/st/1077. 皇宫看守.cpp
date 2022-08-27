#include <bits/stdc++.h>
using namespace std;
const int N = 1510, M = N * 2;

int n,root;
int h[N], e[M], ne[M], idx;
int w[N],f[N][3];
bool st[N],is_leaf[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u){
    f[u][2] = w[u];
    int sum = 0;
    for(int i = h[u];~i;i=ne[i]){
        int j = e[i];
        dfs(j);
        f[u][0] += min({f[j][2],f[j][1]});
        f[u][2] += min({f[j][0],f[j][1],f[j][2]});
        sum += min(f[j][2],f[j][1]);
    }
    f[u][1] = 1e9;
    for(int i = h[u];~i;i=ne[i]){
        int j = e[i];
        f[u][1] = min(f[u][1], sum - min(f[j][1],f[j][2]) + f[j][2]);
    }

}

int main(){
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        int id,cnt;
        scanf("%d",&id);
        scanf("%d",&w[id]);
        scanf("%d",&cnt);
        while(cnt--){
            int x; scanf("%d",&x);
            add(id,x);
            st[x] = true;
        }
    }
    if(n==1) {
        printf("%d\n",w[n]);
        return 0;
    }
    root = 1;
    while(st[root]) root ++;
    dfs(root);
    printf("%d\n",min(f[root][1],f[root][2]));
}