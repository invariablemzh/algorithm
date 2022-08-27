#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> PII;
const int N = 50010, M = 2e5 + 10, INF = 0x3f3f3f3f;

int n,m;
int h[N], w[M], e[M], ne[M], idx;
bool st[N];
int dist[6][N],source[6];

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

void dijkstra(int start, int dist[]){
    memset(dist, 0x3f, N * 4);
    memset(st,false,sizeof(st));
    dist[start] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, start});
    while (heap.size()){
        auto t = heap.top();
        heap.pop();
        int ver = t.second, distance = t.first;
        if (st[ver]) continue;
        st[ver] = true;
        for (int i = h[ver]; i != -1; i = ne[i]){
            int j = e[i];
            if (dist[j] > dist[ver] + w[i]){
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int dfs(int u,int start,int distance){
    if(u>5) return distance;
    int res = INF;
    for(int i = 1;i<=5;i++){
        if(!st[i]){
            st[i] = true;
            res = min(res,dfs(u+1,i,distance + dist[start][source[i]]));
            st[i] = false;
        }
    }
    return res;
}

int main(){
    memset(h,-1,sizeof(h));
    cin >> n >> m;
    source[0] = 1;
    for(int i = 1;i<=5;i++) cin >> source[i];
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c), add(b,a,c);
    }
    for(int i = 0;i<=5;i++) dijkstra(source[i],dist[i]);
    memset(st,false,sizeof(st));
    printf("%d\n",dfs(1,0,0));
}