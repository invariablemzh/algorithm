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

const int N = 10010, M = 30010;

int n, m;
int h[N], e[M], ne[M], idx;
int dfn[N], low[N], timestamp;
int root, ans;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx ++ ;
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++ timestamp;

    int cnt = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
            if (low[j] >= dfn[u]) cnt ++ ;	//u删掉后j单独出来--多一个单独子树。 1. 如果u不是根节点 那么u是割点 2. u是根节点 至少有两个子节点yi 
        }
        else low[u] = min(low[u], dfn[j]);
    }

    if (u != root) cnt ++ ;	//如果x非根节点 还要多+1

    ans = max(ans, cnt);
}

void solve(){
    memset(dfn,0,sizeof(dfn));
    memset(h,-1,sizeof(h));
    idx = 0, timestamp = 0;
    ans = 0;
    while(m--){
        int a,b;
        cin >> a >> b;
        add(a,b), add(b,a);
    }
    int cnt = 0;
    for(root = 0;root<n;root++){
        if(!dfn[root]){
            cnt ++;
            tarjan(root);
        }
    }
    cout << ans + cnt - 1 << '\n';

}

int main(){
    FAST 
    int T = 1; 
    while(cin >> n >> m, n || m) solve(); 
}