#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 2010;

int n, m, S, T;
double g[N][N];
double dist[N];
bool st[N];

double dijkstra(){
    dist[S] = 1;
    for (int i = 0; i < n - 1; i ++ ){
        int t = -1;
        for (int j = 1; j <= n; j ++ )
            if (!st[j] && (t == -1 || dist[t] < dist[j]))
                t = j;
        for (int j = 1; j <= n; j ++ )
            dist[j] = max(dist[j], dist[t] * g[t][j]);
        st[t] = true;
    }
    return dist[T];
}

int main(){
    scanf("%d%d", &n, &m);
    while (m -- ){
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        double z = (100.0-c)/100;
        g[a][b] = g[b][a] = max(g[a][b], z);
    }
    cin >> S >> T;
    printf("%.8lf\n", 100.0 / dijkstra());
    return 0;
}