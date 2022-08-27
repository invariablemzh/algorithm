#include <bits/stdc++.h>
using namespace std;
const int N = 25010, M = 50000 * 3 + 10, INF = 0x3f3f3f3f;
typedef pair<int,int> PII;
#define x first
#define y second

int n,mr,mp,S;
int h[N],e[M],ne[M],w[M],idx;
int id[N],din[N],dist[N];
int bcnt;
bool st[N];
vector<int> block[N];
queue<int> q;

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dfs(int u,int bid){
    id[u] = bid, block[bid].push_back(u);
    for(int i = h[u];~i;i=ne[i]){
        int j = e[i];
        if(!id[j]) dfs(j,bid);
        
    }
}

void dijkstra(int bid){
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    for(auto t : block[bid]){
        heap.push({dist[t],t});
    }
    while (heap.size()){
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if (st[ver]) continue;
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i]){
            int j = e[i];
            if(id[j]!=id[ver]&&--din[id[j]]==0) q.push(id[j]);
            if (dist[j] > dist[ver] + w[i]){
                dist[j] = dist[ver] + w[i];
                if(id[j]==id[ver]) heap.push({dist[j], j});
            }
        }
    }
}

void topsort(){
    memset(dist,0x3f,sizeof(dist));
    dist[S] = 0;
    for(int i = 1;i<=bcnt;i++){
        if(!din[i]) {
            q.push(i);
        }
    } 
    while(q.size()){
        int t = q.front();
        q.pop();
        dijkstra(t);
    }
}

int main(){
    memset(h,-1,sizeof(h));
    cin >> n >> mr >> mp >> S;
    while(mr--){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c), add(b,a,c);
    }
    for(int i = 1;i<=n;i++){
        if(!id[i]){
            bcnt++;
            dfs(i,bcnt);
        }
    }
    while(mp--){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c);
        din[id[b]]++;
    }
    topsort();
    for(int i = 1;i<=n;i++){
        if(dist[i]>INF/2) puts("NO PATH");
        else printf("%d\n",dist[i]);
    }
}