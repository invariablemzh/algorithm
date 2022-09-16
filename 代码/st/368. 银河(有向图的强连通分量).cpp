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

const int N = 100010, M = 600010;

int n, m;
int h[N], e[M], ne[M], idx, hs[N], w[M];
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt, Size[N];
int dout[N],f[N];

void add(int *h, int a, int b,int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
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

void solve(){
    memset(h,-1,sizeof(h));
    memset(hs,-1,sizeof(hs));
    cin >> n >> m;
    while(m--){
        int t,a,b;
        cin >> t >> a >> b;
        if(t==1) add(h,a,b,0),add(h,b,a,0);
        else if(t==2) add(h,a,b,1);
        else if(t==3) add(h,b,a,0);
        else if(t==4) add(h,b,a,1);
        else add(h,a,b,0); 
    }
    for(int i = 1;i<=n;i++) add(h,0,i,1);
    tarjan(0);
    bool flag = true;
    for(int i = 1;i<=n;i++){
        for(int j = h[i];~j;j=ne[j]){
            int k = e[j];
            int a = id[i], b = id[k];
            if(a==b){
                if(w[j]>0){
                    flag = false;
                }
            }
            if(a!=b){
                add(hs,a,b,w[j]);
            }
        }
    }
    for(int i = scc_cnt;i;i--){
        if(!f[i]){
            f[i] = 1;
        }
        for(int j = hs[i];~j;j=ne[j]){
            int k = e[j];
            f[k] = max(f[k],f[i] + w[j]);
        }
    }
    ll res = 0;
    for(int i = 1;i<=n;i++){
        res += f[id[i]];
    }
    if(!flag) res = -1;
    cout << res << '\n';
}

int main()
{
    FAST 
    int T = 1; 
    // cin >> T;
    while(T--) solve(); 
}