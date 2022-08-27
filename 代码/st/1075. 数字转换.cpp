#include <bits/stdc++.h>
using namespace std;
const int N = 50010, M = N * 2;

int n;
int sum[N],ans;
int h[N],e[M],ne[M],idx;
bool st[N];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfs(int u,int fa){
    st[u] = true;
    int dist = 0;
    int d1 = 0, d2 = 0;
    for(int i = h[u];~i;i=ne[i]){
        int j = e[i];
        if(j==fa) continue;
        if(!st[j]){
            int d = dfs(j,u) + 1;
            if(d>=d1) d2 = d1, d1 = d;
            else if(d>d2) d2 = d;
            dist = max(dist,d1);
        }
        
    }
    ans = max(d1 + d2,ans);
    return dist;
}

int main(){
    memset(h,-1,sizeof(h));
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        for(int j = 2;j<=n/i;j++){
            sum[i*j] += i;
        }
    }
    for(int i = 1;i<=n;i++){
        if(sum[i]<i){
            add(sum[i],i);
        }
            
    }
    for(int i = 1;i<=n;i++){
        if(!st[i]) dfs(i,-1);
    }
    //dfs(1,-1);
    printf("%d\n",ans);
}