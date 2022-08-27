#include <bits/stdc++.h>
using namespace std;
const int N = 510, M = 1450 * 2 + 10, P = 810, INF = 0x3f3f3f3f;
typedef pair<int,int> PII;

int n,p,m;
int s[N];
int h[P],e[M],ne[M],w[M],idx;
int dist[P];
bool st[P];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra(int S){
    memset(dist,0x3f,sizeof(dist));
    memset(st,false,sizeof(st));
    dist[S] = 0;
    priority_queue<PII,vector<PII>,greater<PII>> q;
    q.push({0,S});
    while(q.size()){
        PII t = q.top();
        q.pop();
        int ver = t.second;
        if(st[ver]) continue;
        st[ver] = true;
        for(int i = h[ver];~i;i=ne[i]){
            int j = e[i];
            if(dist[j]>dist[ver]+w[i]){
                dist[j] = dist[ver] + w[i];
                q.push({dist[j],j});
            }
        }
    }
    int res = 0;
    for(int i = 1;i<=n;i++){
        if(dist[s[i]]==INF) return INF;
        res += dist[s[i]];
    }
    return res;
}


int main(){
    memset(h,-1,sizeof(h));
    scanf("%d%d%d",&n,&p,&m);
    for(int i = 1;i<=n;i++) scanf("%d",&s[i]);
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c), add(b,a,c);
    }
    int res = INF;
    for(int i = 1;i<=p;i++){
        res = min(res,dijkstra(i));
    }
    printf("%d\n",res);
}