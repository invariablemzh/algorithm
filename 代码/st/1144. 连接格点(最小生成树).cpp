#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 1010, M = 2010010, INF = 0x3f3f3f3f;

int n, m, cnt, es;
int p[M], id[N][N];

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
    sort(edges, edges + es);
    int res = 0;
    for (int i = 0; i < es; i ++ ){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b){
            p[a] = b;
            res += w;
        }
    }
    cout << res << '\n';
}

int main(){
    FAST
    cin >> n >> m;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            id[i][j] = ++ cnt;
        }
    }
    for (int i = 1; i <= cnt; i ++ ) p[i] = i;    // 初始化并查集

    int x1, y1, x2, y2;
    while(cin >> x1 >> y1 >> x2 >> y2){
        int a = id[x1][y1], b = id[x2][y2];
        a = find(a), b = find(b);
        if(a!=b) p[a] = b;
    }
    int dx[4] = {1,0}, dy[4] = {0,1};
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            for(int k = 0;k<2;k++){
                int a = i + dx[k], b = j + dy[k];
                if(a<1||a>n||b<1||b>m) continue;
                int t1 = id[i][j], t2 = id[a][b];
                if(k&1) edges[es++] = {t1,t2,2};
                else edges[es++] = {t1,t2,1};
            }
        }
    }

    kruskal();
    

    return 0;
}