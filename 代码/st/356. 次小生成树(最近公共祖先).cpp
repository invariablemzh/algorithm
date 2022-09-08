#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
typedef long long ll;
const int N = 1e5 + 10, M = 3e5 + 10, INF = 0x3f3f3f3f;
int n,m,root;
int h[N],e[M],ne[M],w[M],idx;
int depth[N], fa[N][17];
int d1[N][17], d2[N][17];
int p[N];

struct Edge{
    int a, b, w;
    bool f;
    bool operator< (const Edge &W)const{
        return w < W.w;
    }
}edges[M];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

ll kruskal(){
    sort(edges, edges + m);
    for (int i = 1; i <= n; i ++ ) p[i] = i;    // 初始化并查集
    ll res = 0;
    for (int i = 0; i < m; i ++ ){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b){
            edges[i].f = true;
            p[a] = b;
            res += w;
        }
    }
    return res;
}



void bfs(){
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[1] = 1;
    queue<int> q;
    q.push(1);
    while (q.size()){
        int t = q.front(); q.pop();
        for (int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if (depth[j] > depth[t] + 1){
                depth[j] = depth[t] + 1;
                q.push(j);
                fa[j][0] = t;
                d1[j][0] = w[i], d2[j][0] = -INF;
                for (int k = 1; k <= 16; k ++ ){
                    int anc = fa[j][k - 1];
                    fa[j][k] = fa[anc][k - 1];
                    int distance[4] = {d1[j][k-1],d2[j][k-1],d1[anc][k-1],d2[anc][k-1]};
                    d1[j][k] = d2[j][k] = -INF;
                    for(int u = 0;u<4;u++){
                        int d = distance[u];
                        if(d>d1[j][k]) d2[j][k] = d1[j][k], d1[j][k] = d;
                        else if(d!=d1[j][k]&&d>d2[j][k]) d2[j][k] = d;
                    }
                }
            }
        }
    }
}

int lca(int a, int b, int w){
    static int distance[N*2];
    int cnt = 0;
    if (depth[a] < depth[b]) swap(a, b);
    for (int k = 16; k >= 0; k -- )
        if (depth[fa[a][k]] >= depth[b]){
            distance[cnt++] = d1[a][k];
            distance[cnt++] = d2[a][k];
            a = fa[a][k];
        }
            
    if(a!=b){
        for (int k = 16; k >= 0; k -- ){
            if (fa[a][k] != fa[b][k]){
                distance[cnt++] = d1[a][k];
                distance[cnt++] = d2[a][k];
                distance[cnt++] = d1[b][k];
                distance[cnt++] = d2[b][k];
                a = fa[a][k], b = fa[b][k];
            }
        }
        distance[cnt++] = d1[a][0];
        distance[cnt++] = d1[b][0];
    }
    int dist1 = -INF, dist2 = -INF;
    for(int i = 0;i<cnt;i++){
        int d = distance[i];
        if(d>dist1) dist2 = dist1, dist1 = d;
        else if(d!=dist1&&d>dist2) dist2 = d;
    }
    if(w > dist1) return w - dist1;
    if(w > dist2) return w - dist2;
    return INF;
}

void solve(){
    cin >> n >> m;
    for (int i = 0; i < m; i ++ ){
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w, false};
    }
    ll sum = kruskal();
    memset(h,-1,sizeof(h));
    for(int i = 0;i<m;i++){
        if(edges[i].f){
            int a = edges[i].a, b = edges[i].b, w = edges[i].w;
            add(a,b,w), add(b,a,w);
        }
    }
    bfs();
    ll res = 1e18;
    for(int i = 0;i<m;i++){
        if(!edges[i].f){
            int a = edges[i].a, b = edges[i].b, w = edges[i].w;
            res = min(res,sum + lca(a,b,w));
            
        }
    }
    cout << res << '\n';
}



int main(){
    FAST
    int T = 1;
    // cin >> T;
    while(T--) solve();
    
}