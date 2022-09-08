#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 4e4 + 10, M = N * 2;
int n,m,root;
int h[N],e[M],ne[M],idx;
int depth[N], fa[N][16];

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void bfs(){
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

void solve(){
    memset(h,-1,sizeof(h));
    cin >> n;
    for(int i = 1;i<=n;i++){
        int a,b;
        cin >> a >> b;
        if(b==-1) root = a;
        else add(a,b), add(b,a);
    }
    bfs();
    cin >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        int p = lca(a,b);
        if(p==a) cout << 1 << '\n';
        else if(p==b) cout << 2 << '\n';
        else cout << 0 << '\n';
    }
}

int main(){
    FAST
    int T = 1;
    // cin >> T; 
    while(T--) solve();
}