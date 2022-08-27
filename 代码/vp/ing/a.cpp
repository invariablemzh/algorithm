#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 1510, M = 4100 * 2, INF = 1e8;;
int cnt[N];
int n ,S, T;
int h[N], e[M], f[M], ne[M], idx;
int q[N], d[N], cur[N];

void add(int a, int b, int c){
    e[idx] = b, f[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
    e[idx] = a, f[idx] = 0, ne[idx] = h[b], h[b] = idx ++ ;
}

bool bfs(){
    queue<int> q;
    memset(d, -1, sizeof d);
    while(q.size()) q.pop();
    q.push(S);
    d[S] = 0, cur[S] = h[S];
    while (q.size()){
        int t = q.front(); q.pop();
        for (int i = h[t]; ~i; i = ne[i]){
            int ver = e[i];
            if (d[ver] == -1 && f[i]){
                d[ver] = d[t] + 1;
                cur[ver] = h[ver];
                if (ver == T)  return true;
                q.push(ver);
                
            }
        }
    }
    return false;
}

int find(int u, int limit){
    if (u == T) return limit;
    int flow = 0;
    for (int i = cur[u]; ~i && flow < limit; i = ne[i]){
        cur[u] = i;  // 当前弧优化
        int ver = e[i];
        if (d[ver] == d[u] + 1 && f[i]){
            int t = find(ver, min(f[i], limit - flow));
            if (!t) d[ver] = -1;
            f[i] -= t, f[i ^ 1] += t, flow += t;
        }
    }
    return flow;
}

int dinic(){
    int r = 0, flow;
    while (bfs()) while (flow = find(S, INF)) r += flow;
    return r;
}

void solve(){
    memset(cur,0,sizeof(cur));
    memset(h,-1,sizeof(h));
    memset(cnt,0,sizeof(cnt));
    idx = 0;
    int m1,m2;
    cin >> n >> m1 >> m2;
    if(n==1){
        cout << "YES" << '\n';
        return;
    }
    while(m1--){
        int x,y,z;
        cin >> x >> y >> z;
        if(z==1) cnt[x]++;
        else cnt[y]++;
    }
    int cnt1 = 0;
    S = 0, T = m2 + n + 1;
    for(int i = 1;i<=m2;i++){
        int x,y;
        cin >> x >> y;
        if(x==1||y==1) {
            cnt1 ++;
            cnt[1] ++;
        }
        else{
            add(S,i,1);
            add(i,x+m2,1);
            add(i,y+m2,1);
        }
    }
    for(int i = 2;i<=n;i++){
        if(cnt[i]>cnt[1]){
            cout << "NO" << '\n';
            return;
        }
    }
    // cout << cnt1<<endl;
    // for(int i = 2;i<=n;i++) cout << cnt[i] << ' ';
    // cout << endl;
    for(int i = 2;i<=n;i++){
        add(i+m2,T,cnt[1]-cnt[i]);
    }
    int t = dinic();
    // for (int i = 0; i < idx; i += 2)
    //     if (e[i] > m2 && e[i] <= n + m2 && !f[i])
    //         cout << e[i ^ 1] << ' ' << e[i] - m2 << '\n';

    if(t==m2-cnt1) cout << "YES" << '\n';
    else cout << "NO" << '\n';
}

int main(){
    FAST
    int T; cin >> T;
    while(T--) solve();
}