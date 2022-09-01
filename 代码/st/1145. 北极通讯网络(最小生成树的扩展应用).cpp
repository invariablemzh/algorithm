#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

typedef pair<int,int> PII;
const int N = 510, M = 250010, INF = 0x3f3f3f3f;
#define x first
#define y second
int n, k, m;
PII q[N];
int p[N];

struct Edge{
    int a, b;
    double w;
    bool operator< (const Edge &W)const{
        return w < W.w;
    }
}edges[M];

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

double calc(PII a, PII b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx*dx+dy*dy);
}

double kruskal(){
    sort(edges, edges + m);
    for (int i = 1; i <= n; i ++ ) p[i] = i;    // 初始化并查集
    double res = 0;
    int cnt = 0;
    for (int i = 0; i < m; i ++ ){
        int a = edges[i].a, b = edges[i].b;
        double w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b){
            cnt ++ ;
            if(cnt<=n-k) res = max(res,w);
            p[a] = b;
            
        }
    }
    return res;
}

int main(){
    scanf("%d%d",&n,&k);
    for(int i = 0;i<n;i++) scanf("%d%d",&q[i].x, &q[i].y);
    for(int i = 0;i<n;i++){
        for(int j = i+1;j<n;j++){
            edges[m++] = {i, j, calc(q[i],q[j])};
        }
    }
    printf("%.2lf\n",kruskal());
    return 0;
}