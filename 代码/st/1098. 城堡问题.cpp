#include <bits/stdc++.h>
using namespace std;
const int N = 60, M = N * N;
typedef pair<int,int> PII;
#define x first
#define y second

int n,m;
int g[N][N];
bool st[N][N];
PII q[M];

int dx[4] = {0,-1,0,1};
int dy[4] = {-1,0,1,0};

int bfs(int x,int y){
    q[0] = {x,y};
    st[x][y] = true;
    int hh = 0, tt = 0;
    int cnt = 0;
    while(hh<=tt){
        PII t = q[hh++];
        cnt++;
        for(int i = 0;i<4;i++){
            int xx = t.x + dx[i], yy = t.y + dy[i];
            if(xx<1||xx>n||yy<1||yy>m||st[xx][yy]) continue;
            if(g[t.x][t.y]>>i&1) continue;
            st[xx][yy] = true;
            q[++tt] = {xx,yy};
        }
    }
    return cnt;
}

int main(){
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            scanf("%d",&g[i][j]);
        }
    }
    int ans = 0;
    int cnt = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(!st[i][j]){
                ans = max(ans,bfs(i,j));
                cnt++;
            }
        }
    }
    printf("%d\n",cnt);
    printf("%d\n",ans);
}