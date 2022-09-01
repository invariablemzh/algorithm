#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 510, M = 20010, INF = 0x3f3f3f3f;
typedef long long ll;
int n, m;
int p[N];
int dist1[N][N], dist2[N][N];
int h[N],e[M],w[M],ne[M],idx;

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

void dfs(int u,int fa,int maxd1, int maxd2, int d1[], int d2[]){
    d1[u] = td1, d2[u] = td2;
    for(int i = h[u];~i;i=ne[i]){
        int j = e[i];
        if(j==fa) continue;
        int td1 = maxd1, td2 = maxd2;
        if(w[i] > td1) td2 = td1, td1 = w[i];
        else if(w[i] < td1 && w[i] > td2) td2 = w[i];
        dfs(j,u,td1,td2,d1,d2);
    }
}

void solve(){
    memset(h,-1,sizeof(h));
    cin >> n >> m;
    for(int i = 0;i<m;i++){
        int a,b,w;
        cin >> a >> b >> w;
        edges[i] = {a,b,w,false};
    }
    sort(edges, edges + m);
    for (int i = 1; i <= n; i ++ ) p[i] = i;    // 初始化并查集
    ll sum = 0;
    for (int i = 0; i < m; i ++ ){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        int pa = find(a), pb = find(b);
        if (pa != pb){
            p[pa] = pb;
            add(a,b,w), add(b,a,w);
            sum += w;
        }
    }
    for(int i = 1;i<=n;i++){
        dfs(i,-1,-1e9,-1e9,dist1[i],dist2[i]);
    }
    
    ll res = 1e18;
    for(int i =0;i<m;i++){
        if(!edges[i].f){
            int a = edges[i].a, b = edges[i].b, w = edges[i].w;
            ll t;
            if(w > dist1[a][b]){
                t = sum + w - dist1[a][b]; 
            }
            else if(w > dist2[a][b]){
                t = sum + w - dist2[a][b];
            }
            res = min(res,t);
        }
    }
    cout << res << '\n';

}

int main(){
    FAST
    int T = 1; 
    // cin >> T;
    while(T--) solve();
    return 0;
}