#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 110, INF = 0x3f3f3f3f;
int n, m;
int g[N][N];
int dist[N];
bool st[N];

int prim(){
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    for (int i = 0; i < n; i ++ ){
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] > dist[j]))
                t = j;
        if (i && dist[t] == INF) return INF;
        if (i) res += dist[t];
        st[t] = true;
        for (int j = 1; j <= n; j ++ ) dist[j] = min(dist[j], g[t][j]);
    }
    return res;
}


int main(){
    FAST
    cin >> n;
    memset(g, 0x3f, sizeof g);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            int c; cin >> c;
            g[i][j] = g[j][i] = min(g[i][j], c);
        }
    }
    cout << prim() << '\n';
    return 0;
}