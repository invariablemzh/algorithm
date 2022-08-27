#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = 21010;
typedef pair<int, int> PII;

int n,m,S;
int h[N],e[M],w[M],ne[M],idx;
int dist[N];
bool st[N];

void add(int a, int b, int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx ++ ;
}

int dijkstra(){
    memset(st,false,sizeof(st));
    memset(dist, 0x3f, sizeof dist);
    dist[0] = 0;
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, 0});
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
    if (dist[S] == 0x3f3f3f3f) return -1;
    return dist[S];
}



int main(){
    while(~scanf("%d%d%d", &n, &m, &S)){
        memset(h, -1, sizeof h);
        idx = 0;
        while (m -- ){
            int a, b, c;
            scanf("%d%d%d", &a, &b, &c);
            add(a, b, c);
        }
        int w; scanf("%d",&w);
        while(w--){
            int x; scanf("%d",&x);
            add(0,x,0);
        }
        cout << dijkstra() << endl;
        
    }
}