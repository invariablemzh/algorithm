#include <bits/stdc++.h>
using namespace std;
const int N = 510;
typedef pair<int,int> PII;
#define x first
#define y second

int n,m;
char g[N][N];
int dist[N][N];
bool st[N][N];
deque<PII> q;

int bfs(){
    memset(dist,0x3f,sizeof(dist));
    memset(st,false,sizeof(st));
    dist[0][0] = 0;
    q.push_front({0,0});
    char cs[] = "\\/\\/";
    int dx[4] = {-1,-1,1,1}, dy[4] = {-1,1,1,-1};
    int ix[4] = {-1,-1,0,0}, iy[4] = {-1,0,0,-1};
    while(q.size()){
        PII t = q.front();
        q.pop_front();
        if(st[t.x][t.y]) continue;
        st[t.x][t.y] = true;
        for(int i = 0;i<4;i++){
            int a = dx[i] + t.x, b = dy[i] + t.y;
            if(a<0||a>n||b<0||b>m) continue;
            int ca = ix[i] + t.x, cb = iy[i] + t.y;
            int d = dist[t.x][t.y] + (g[ca][cb]!=cs[i]);
            if(d<dist[a][b]){
                dist[a][b] = d;
                if(g[ca][cb]!=cs[i]) q.push_back({a,b});
                else q.push_front({a,b});
            }
        }
    }
    return dist[n][m];
}

int main(){
    int T; scanf("%d",&T);
    while(T--){
        scanf("%d%d",&n,&m);
        for(int i = 0;i<n;i++) scanf("%s",g[i]);
        int t = bfs();
        if(t==0x3f3f3f3f) puts("NO SOLUTION");
        else printf("%d\n",t);
    }
}