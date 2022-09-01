//整体思维
#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 6010, INF = 0x3f3f3f3f;
int n;
int p[N], sz[N];

struct Edge{
    int a, b, w;
    bool operator< (const Edge &W)const{
        return w < W.w;
    }
}edges[N];

int find(int x){
    if (p[x] != x) p[x] = find(p[x]);
    return p[x];
}

int kruskal(){
    sort(edges, edges + n - 1);
    for (int i = 1; i <= n; i ++ ) p[i] = i, sz[i] = 1;    // 初始化并查集
    int res = 0;
    for (int i = 0; i < n - 1; i ++ ){
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a), b = find(b);
        if (a != b){
            res += (sz[a] * sz[b] - 1) * (w + 1);
            sz[b] += sz[a];
            p[a] = b;
        }
    }
    return res;
}

void solve(){
    cin >> n;
    for(int i = 0;i<n-1;i++){
        int a,b,c;
        cin >> a >> b >> c;
        edges[i] = {a,b,c};
    }
    cout << kruskal() << '\n';
}

int main(){
    FAST
    int T; cin >> T;
    while(T--) solve();
    return 0;
}