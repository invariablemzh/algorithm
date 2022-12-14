#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = 20010, INF = 0x3f3f3f3f;

int n,m,S,T;
int h[N],e[M],ne[M],w[M],idx;
int dist[N][2],cnt[N][2];
bool st[N][2];

struct Ver{
    int id,type,dist;
    bool operator>(const Ver &W)const{
        return dist > W.dist;
    }
};

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dijkstra(){
    memset(dist,0x3f,sizeof(dist));
    memset(st,false,sizeof(st));
    memset(cnt,0,sizeof(cnt));
    dist[S][0] = 0;
    cnt[S][0] = 1;
    priority_queue<Ver,vector<Ver>,greater<Ver>> heap;
    heap.push({S,0,0});
    while(heap.size()){
        Ver t = heap.top();
        heap.pop();
        int ver = t.id, type = t.type, distance = t.dist, count = cnt[ver][type];
        if(st[ver][type]) continue;
        st[ver][type] = true;
        for(int i = h[ver];~i;i=ne[i]){
            int j = e[i];
            if(dist[j][0] > distance + w[i]){
                dist[j][1] = dist[j][0], cnt[j][1] = cnt[j][0];
                heap.push({j,1,dist[j][1]});
                dist[j][0] = distance + w[i], cnt[j][0] = count;
                heap.push({j,0,dist[j][0]});
            }
            else if(dist[j][0] == distance + w[i]) cnt[j][0] += count;
            else if(dist[j][1] > distance + w[i]){
                dist[j][1] = distance+ w[i];
                cnt[j][1] = count;
                heap.push({j,1,dist[j][1]});
            }
            else if(dist[j][1] == distance + w[i]) cnt[j][1] += count;
        }
    }
    int res = cnt[T][0];
    if(dist[T][0] + 1 == dist[T][1]) res += cnt[T][1];
    return res;
}

int main(){
    int Cases; scanf("%d",&Cases);
    while(Cases--){
        memset(h,-1,sizeof(h));
        idx = 0;
        scanf("%d%d",&n,&m);
        while(m--){
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            add(a,b,c);
        }
        scanf("%d%d",&S,&T);
        printf("%d\n",dijkstra());
    }
}