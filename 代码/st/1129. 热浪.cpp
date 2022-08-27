#include <bits/stdc++.h>
using namespace std;
const int N = 2510, M = 6200 * 2 + 10;
typedef pair<int,int> PII;

int n,m,S,T;
int h[N],e[M],ne[M],idx,w[M];
int dist[N];
bool st[N];
priority_queue<PII,vector<PII>,greater<PII> > q;

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void dijkstra(){
    memset(dist,0x3f,sizeof(dist));
    dist[S] = 0;
    q.push({0,S});
    while(q.size()){
        PII t = q.top();
        q.pop();
        int distance = t.first, u = t.second;
        if(st[u]) continue;
        st[u] = true;
        for(int i = h[u];~i;i=ne[i]){
            int j = e[i];
            if(!st[j]&&dist[j]>distance+w[i]){
                dist[j] = distance + w[i];
                q.push({dist[j],j});
            }
        }
    }
}

int main(){
    memset(h,-1,sizeof(h));
    scanf("%d%d%d%d",&n,&m,&S,&T);
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(a,b,c), add(b,a,c);
    }
    dijkstra();
    printf("%d\n",dist[T]);
    return 0;
}