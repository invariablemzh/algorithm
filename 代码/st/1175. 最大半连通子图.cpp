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

const int N = 100010, M = 2000010;

int n, m, X, K, C = 1;
int h[N], e[M], ne[M], idx, h2[N];
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt, Size[N];
int din[N], f[N], g[N];

void add(int *h, int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++ timestamp;
    stk[ ++ top] = u, in_stk[u] = true;
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }
        else if (in_stk[j]) low[u] = min(low[u], dfn[j]);
    }

    if (dfn[u] == low[u])
    {
        ++ scc_cnt;
        int y;
        do {
            y = stk[top -- ];
            in_stk[y] = false;
            id[y] = scc_cnt;
            Size[scc_cnt] ++ ;
        } while (y != u);
    }
}

void topsort(){
    queue<int> q;
    for (int i = 1; i <= scc_cnt; i ++ ){    
        if (!din[i]) {
            f[i] = Size[i];
            g[i] = 1;
            q.push(i);
        }
    }
    // cout << '\n';
    while (q.size()){
        int t = q.front(); q.pop();
        for (int i = h2[t]; i != -1; i = ne[i]){
            int j = e[i];
            if(f[j] < f[t] + Size[j]){
                f[j] = f[t] + Size[j];
                g[j] = g[t];
            }
            else if(f[j] == f[t] + Size[j]){
                g[j] = (g[j] + g[t]) % X;
            }
            if(--din[j]==0) q.push(j);
        }
        
    }
    for(int i = 1;i<=scc_cnt;i++){
        if(f[i]>K){
            K = f[i];
            C = g[i];
        }
        else if(f[i] == K) C = (C + g[i]) % X;
    }
}

void solve(){
    memset(h,-1,sizeof(h));
    memset(h2,-1,sizeof(h2));
    cin >> n >> m >> X;
    while(m--){
        int a, b;
        cin >> a >> b;
        add(h,a,b);
    }
    for(int i = 1;i<=n;i++){
        if(!dfn[i]) tarjan(i);
    }
    // for(int i = 1;i<=n;i++){
    //     cout << i << ' ' << id[i] << '\n';
    // }
    unordered_set<ll> S;
    for(int i = 1;i<=n;i++){
        for(int j = h[i];~j;j=ne[j]){
            int k = e[j];
            int a = id[i], b = id[k];
            ll hash = a * 1000000ll + b;
            if(a!=b&&!S.count(hash)){
                din[b] ++;
                add(h2,a,b);
                S.insert(hash);
            }
        }
    }
    topsort();
    cout << K << '\n' << C << '\n';

}

int main(){
    FAST 
    int T = 1; 
    // cin >> T;
    while(T--) solve(); 
}