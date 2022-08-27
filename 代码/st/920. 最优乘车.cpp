#include <bits/stdc++.h>
using namespace std;
const int N = 510, INF = 0x3f3f3f3f;

int n,m;
int q[N],stop[N],dist[N];
int f[N][N];
bool st[N],g[N][N];

void bfs(){
    memset(dist,0x3f,sizeof(dist));
    q[0] = 1;
    dist[1] = 0;
    int hh = 0, tt = 0;
    while(hh<=tt){
        int t = q[hh++];
        for(int i = 1;i<=n;i++){
            if(g[t][i]&&dist[i]>dist[t]+1){
                dist[i] = dist[t] + 1;
                q[++tt] = i;
            }
        }
    }
}

int main(){
    cin >> m >> n;
    string line;
    getline(cin,line);
    while(m--){
        getline(cin,line);
        stringstream ssin(line);
        int p, cnt = 0;
        while(ssin>>p) stop[cnt++] = p;
        for(int i = 0;i<cnt;i++){
            for(int j = i+1;j<cnt;j++){
                g[stop[i]][stop[j]] = true;
            }
        }
    }
    bfs();
    if(dist[n]==INF) puts("NO");
    else printf("%d\n",max(dist[n]-1,0));
}