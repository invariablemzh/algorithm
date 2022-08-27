#include <bits/stdc++.h>
using namespace std;
const int N = 20, M = (1<<15)+5;

int n,m,K,xs,ys,xt,yt;
int f[M];
int hq[N][N],zq[N][N],mp[N][N];

struct Edge{
    int s[2],t[2];
}edges[N];

bool dfs(int x,int y){
    mp[x][y] = 1;
    if(x==xt&&y==yt){
        return 1;
    }
    bool res = 0;
    //上
    if(x>=1&&!mp[x-1][y]&&!hq[x][y]){
        res|=dfs(x-1,y);
    }
    //下
    if(x+1<n&&!mp[x+1][y]&&!hq[x+1][y]){ 
        res|=dfs(x+1,y);
    }

    //左
    if(y>=1&&!mp[x][y-1]&&!zq[x][y]){ 
        res|=dfs(x,y-1);
    }

    //右  
    if(y+1<m&&!mp[x][y+1]&&!zq[x][y+1]){ 
        res|=dfs(x,y+1);
    }
    return res;
}

bool check(int state){
    memset(hq,0,sizeof(hq));
    memset(zq,0,sizeof(zq));
    memset(mp,0,sizeof(mp));
    for(int i = 0;i<K;i++){
        if(!(state>>i&1)){
            if(edges[i].s[0]==edges[i].s[1]){
                for(int j = edges[i].t[0];j<edges[i].t[1];j++){
                    hq[edges[i].s[0]][j] = true;
                }
            }
            else if(edges[i].t[0]==edges[i].t[1]){
                for(int j = edges[i].s[0];j<edges[i].s[1];j++){
                    zq[j][edges[i].t[0]] = true;
                }
            }
        }
    }
    return dfs(xs,ys);
}

int count(int state){
    int res = 0;
    for(int i = 0;i<K;i++){
        res += state>>i&1;
    }
    return res;
}

void solve(){
    scanf("%d%d%d%d%d%d%d",&n,&m,&K,&xs,&ys,&xt,&yt);
    for(int i = 0;i<K;i++){
        scanf("%d%d%d%d",&edges[i].s[0],&edges[i].t[0],&edges[i].s[1],&edges[i].t[1]);
        if(edges[i].s[0]==edges[i].s[1]&&edges[i].t[0]>edges[i].t[1]){
            swap(edges[i].t[0],edges[i].t[1]);
        }
        else if(edges[i].t[0]==edges[i].t[1]&&edges[i].s[0]>edges[i].s[1]){
            swap(edges[i].s[0],edges[i].s[1]);
        }
    }
    memset(f,false,sizeof(f));
    int ans = K;
    for(int i = 0;i<1<<K;i++){
        if(f[i]) continue;
        f[i] = check(i);
        if(f[i]){
            ans = min(ans,count(i));
            for(int j = 0;j<K;j++){
                f[i|(1<<j)] |= f[i];
            }
            // cout<<i<<endl;
        }
    }
    printf("%d\n",ans);
}

int main(){
    int T; scanf("%d",&T);
    while(T--) solve();
}