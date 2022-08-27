#include <bits/stdc++.h>
using namespace std;
const int N = 11, M  = 360, P = 1 << 10;
typedef pair<int,int> PII;
#define x first
#define y second

int n,m,p,k;
int h[N*N],e[M],w[M],ne[M],idx;
int dist[N*N][P],g[N][N], key[N*N];
bool st[N*N][P];
set<PII> edges;

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void build(){
    int dx[4] = {0,1,0,-1}, dy[4] = {1,0,-1,0};
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            for(int u = 0;u<4;u++){
                int x = i + dx[u], y = j + dy[u];
                if(x<=0||x>n||y<=0||y>m) continue;
                int a = g[x][y], b = g[i][j];
                if(!edges.count({a,b})) add(a,b,0);
            }
        }
    }
}

int bfs(){
    memset(dist,0x3f,sizeof(dist));
    dist[1][0] = 0;
    deque<PII> q;
    q.push_front({1,0});
    while(q.size()){
        PII t = q.front();
        q.pop_front();
        if(st[t.x][t.y]) continue;
        st[t.x][t.y] = true;
        if(t.x == n * m) return dist[t.x][t.y];
        if(key[t.x]){
            int state = t.y | key[t.x];
            if(dist[t.x][state] > dist[t.x][t.y]){
                dist[t.x][state] = dist[t.x][t.y];
                q.push_front({t.x,state});
            }
        }
        for(int i = h[t.x];~i;i=ne[i]){
            int j = e[i];
            if(w[i]&&!(t.y>>w[i]-1&1)) continue;
            if(dist[j][t.y] > dist[t.x][t.y] + 1){
                dist[j][t.y] = dist[t.x][t.y] + 1;
                q.push_back({j,t.y});
            }
        }
    }
    return -1;
}

int main(){
    memset(h,-1,sizeof(h));
    cin >> n >> m >> p >> k;
    for(int i = 1, t = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            g[i][j] = t ++;
        }
    }

    while(k--){
        int x1,y1,x2,y2,c;
        cin >> x1 >> y1 >> x2 >> y2 >> c;
        int a = g[x1][y1], b = g[x2][y2];
        edges.insert({a,b}), edges.insert({b,a});
        if(c) add(a,b,c), add(b,a,c);
    }

    build();

    int s; cin >> s;
    while(s--){
        int a,b,c;
        cin >> a >> b >> c;
        key[g[a][b]] |= 1 << c - 1;
    }

    cout << bfs() << endl;

    return 0;
}