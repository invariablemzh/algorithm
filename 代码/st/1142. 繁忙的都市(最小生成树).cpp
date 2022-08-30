#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 310, M = 16010, INF = 0x3f3f3f3f;

int n, m;
int p[N];

struct Edge{
    int a, b, w;
    bool operator< (const Edge &W)const{
        return w < W.w;
    }
}edges[M];

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

void kruskal(){
    sort(edges, edges + m);
    for (int i = 1; i <= n; i ++ ) p[i] = i;    // 初始化并查集
    int res = 0, cnt = 0;
    for (int i = 0; i < m; i ++ ){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b){
            p[a] = b;
            res = max(res,w);
            cnt ++ ;
        }
    }
    cout << cnt << ' ' << res << '\n';
}

int main(){
    FAST
    cin >> n >> m;
    for (int i = 0; i < m; i ++ ){
        int a, b, w;
        cin >> a >> b >> w;
        edges[i] = {a, b, w};
    }
    kruskal();
    return 0;
}