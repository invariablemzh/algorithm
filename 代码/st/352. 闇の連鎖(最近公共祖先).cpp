#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
#define x first 
#define y second
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 100010, M = 400010;
int n,m;
int h[N],e[M],ne[M],idx;
int depth[N], fa[N][17];
int d[N];
int ans;

void add(int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
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
                for (int k = 1; k <= 16; k ++ )
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
            }
        }
    }
}

int lca(int a, int b){
    if (depth[a] < depth[b]) swap(a, b);
    for (int k = 16; k >= 0; k -- )
        if (depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    if (a == b) return a;
    for (int k = 16; k >= 0; k -- )
        if (fa[a][k] != fa[b][k]){
            a = fa[a][k];
            b = fa[b][k];
        }
    return fa[a][0];
}

int dfs(int u,int fa){
    int res = d[u];
    for(int i = h[u];~i;i=ne[i]){
        int j = e[i];
        if(j==fa) continue;
        int s = dfs(j,u);
        if(s==0) ans += m;
        if(s==1) ans ++;
        res += s;
    }
    return res;
}

void solve(){
    cin >> n >> m;
    memset(h,-1,sizeof(h));
    for(int i = 1;i<=n-1;i++){
        int a,b;
        cin >> a >> b;
        add(a,b), add(b,a);
    }
    bfs();
    for(int i = 1;i<=m;i++){
        int a,b;
        cin >> a >> b;
        int p = lca(a,b);
        d[a]++, d[b]++, d[p] -= 2;
    }
    dfs(1,-1);
    cout << ans << '\n';
}

int main(){
    FAST 
    int T = 1; 
    // cin >> T;
    while(T--) solve(); 
}