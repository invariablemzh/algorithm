#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 1e4 + 10, M = N * 2;
int n,m,root;
int h[N],e[M],ne[M],w[M],idx;
int depth[N], fa[N][16];
int d[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void bfs(int root){
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[root] = 1;
    queue<int> q;
    q.push(root);
    while (q.size()){
        int t = q.front(); q.pop();
        for (int i = h[t]; ~i; i = ne[i]){
            int j = e[i];
            if (depth[j] > depth[t] + 1){
                depth[j] = depth[t] + 1;
                q.push(j);
                fa[j][0] = t;
                for (int k = 1; k <= 15; k ++ )
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }
}

int lca(int a, int b){
    if (depth[a] < depth[b]) swap(a, b);
    for (int k = 15; k >= 0; k -- )
        if (depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    if (a == b) return a;
    for (int k = 15; k >= 0; k -- )
        if (fa[a][k] != fa[b][k]){
            a = fa[a][k];
            b = fa[b][k];
        }
    return fa[a][0];
}

void dfs(int u,int fa){
    for(int i = h[u];~i;i=ne[i]){
        int j = e[i];
        if(j==fa) continue;
        d[j] = d[u] + w[i];
        dfs(j,u);
    }
}

void solve(){
    memset(h,-1,sizeof(h));
    cin >> n >> m;
    for(int i = 1;i<n;i++){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c), add(b,a,c);
    }
    dfs(1,-1);
    bfs(1);
    while(m--){
        int l,r;
        cin >> l >> r;
        int p = lca(l,r);
        cout << d[l] + d[r] - 2 * d[p] << '\n';
    }  
}

int main(){
    FAST
    int T = 1;
    // cin >> T;
    while(T--) solve();
    
}