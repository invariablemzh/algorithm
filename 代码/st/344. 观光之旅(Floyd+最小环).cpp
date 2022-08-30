#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);
const int N = 110, INF = 0x3f3f3f3f;

int n,m;
int d[N][N], g[N][N];
int cnt;
int path[N];
int pos[N][N];

void get_path(int x,int y){
    int k = pos[x][y];
    if(k==0) return;
    get_path(x,k);
    path[cnt++] = k;
    get_path(k,y);
}

int main(){
    cin >> n >> m;
    memset(g,0x3f,sizeof(g));
    for(int i = 1;i<=n;i++) g[i][i] = 0;
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    memcpy(d,g,sizeof(g));
    int res = INF;
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<k;i++){
            for(int j = i+1;j<k;j++){
                if((long long)d[i][j] + g[j][k] + g[k][i] < res){
                    res = d[i][j] + g[j][k] + g[k][i];
                    cnt = 0;
                    path[cnt++] = k;
                    path[cnt++] = i;
                    get_path(i,j);
                    path[cnt++] = j;
                }
            }
        }
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                if(d[i][j] > d[i][k] + d[k][j]){
                    d[i][j] = d[i][k] + d[k][j];
                    pos[i][j] = k;
                }
            }
        }
    }
    if(res==INF) puts("No solution.");
    else{
        for(int i = 0;i<cnt;i++){
            cout << path[i] << ' ';
        }
        cout << '\n';
    }
    return 0;
}