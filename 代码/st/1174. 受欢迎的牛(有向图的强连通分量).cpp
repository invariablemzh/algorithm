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

const int N = 10010, M = 50010;
int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int stk[N], top;
bool in_stk[N];
int id[N], scc_cnt, Size[N];
int dout[N];

void add(int a, int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void tarjan(int u){
    dfn[u] = low[u] = ++ timestamp;
    stk[ ++ top] = u, in_stk[u] = true;
    for (int i = h[u]; i != -1; i = ne[i]){
        int j = e[i];
        if (!dfn[j]){
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }
        else if (in_stk[j]) low[u] = min(low[u], dfn[j]);
    }

    if (dfn[u] == low[u]){
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
    cin >> n >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        add(a,b);
    }
    for(int i = 1;i<=n;i++){
        if(!dfn[i]){
            tarjan(i);
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = h[i];~j;j=ne[j]){
            int k = e[j];
            int a = id[i], b = id[k];
            if(a!=b) dout[a]++;
        }
    }
    int zero = 0, sum = 0;
    for(int i = 1;i<=scc_cnt;i++){
        if(!dout[i]){
            zero++;
            sum += Size[i];
            if(zero>1){
                sum = 0;
                break;
            }
        }
    }
    cout << sum << '\n';
}

int main(){
    FAST 
    int T = 1; 
    // cin >> T;
    while(T--) solve(); 
}