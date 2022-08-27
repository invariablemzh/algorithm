#include <bits/stdc++.h>
using namespace std;
const int N = 110;

char mp[N][N];
int n,m,ans;
int dx[4] = {-1,1,0,0}; //up,down,left,right
int dy[4] = {0,0,-1,1};
int d[N][N][N][4];
bool st[N][N][N][4];

struct T{
    int x,y,k,mb;
};

queue<T> q;

void bfs(){
    for(int i = 0;i<4;i++){
        d[1][1][0][i] = 0;
    }    
    q.push({1,1,0,0});
    while(q.size()){
        T t = q.front(); q.pop();
        // cout<<t.x<<' '<<t.y<<' '<<d[t.x][t.y][t.k][t.mb]<<endl;;
        // if(t.x==1&&t.y==1) continue;
        for(int i = 0;i<4;i++){
            int xx = dx[i] + t.x, yy = dy[i] + t.y;
            if(xx==1&&yy==1) continue;
            if(xx<1||xx>n||yy<1||yy>n||mp[xx][yy]=='*') continue;
            if(t.mb==i){
                if(t.k+1>m) continue;
                if(st[xx][yy][t.k+1][i]) continue;
                d[xx][yy][t.k+1][i] = d[t.x][t.y][t.k][t.mb] + 1;
                st[xx][yy][t.k+1][i] = true;
                q.push({xx,yy,t.k+1,i});
                            
            }
            else{
                if(st[xx][yy][1][i]) continue;
                d[xx][yy][1][i] = d[t.x][t.y][t.k][t.mb] + 1;
                st[xx][yy][1][i] = true;
                q.push({xx,yy,1,i});
                 
            }
            if(xx==n&&yy==n){
                ans = d[t.x][t.y][t.k][t.mb] + 1;
                return;
            }    
        }
    }
}


void solve(){
    ans = 0;
    memset(d,0x3f,sizeof(d));
    memset(st,false,sizeof(st));
    scanf("%d%d",&n,&m);
    getchar();
    for(int i = 1;i<=n;i++) scanf("%s",mp[i]+1);
    bfs();
    if(ans==0||mp[1][1]=='*') puts("-1");
    else printf("%d\n",ans);
    while(q.size()) q.pop();
}

int main(){
    int T; scanf("%d",&T);
    while(T--) solve();
}