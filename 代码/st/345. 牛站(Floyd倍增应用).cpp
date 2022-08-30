/*
d[k,i,j]表示从i到j只经过1～k的话，最短路径是多少
d[k,i,j]表示从i到j，恰好经过k条边的最短路径
d[a+b,i,j] = min(d[a,i,k] + d[b,k,j])
*/

#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0);

const int N = 110;

int k,n,m,S,E;
int g[N][N],res[N][N];
int cnt;
unordered_map<int,int> id;

void mul(int c[][N], int a[][N], int b[][N]){
    static int tmp[N][N];
    memset(tmp,0x3f,sizeof(tmp));
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                tmp[i][j] = min(tmp[i][j], a[i][k] + b[k][j]);
            }
        }
    }
    memcpy(c,tmp,sizeof(tmp));
}

void qmi(){
    memset(res,0x3f,sizeof(res));
    for(int i = 1;i<=n;i++) res[i][i] = 0;
    while(k){
        if(k&1) mul(res,res,g);
        mul(g,g,g);
        k >>= 1;
    }
}

int main(){
    FAST
    cin >> k >> m >> S >> E;
    memset(g,0x3f,sizeof(g));
    if(!id.count(S)) id[S] = ++ n;
    if(!id.count(E)) id[E] = ++ n;
    S = id[S], E = id[E];
    while(m--){
        int a,b,c;
        cin >> c >> a >> b;
        if(!id.count(a)) id[a] = ++ n;
        if(!id.count(b)) id[b] = ++ n;
        a = id[a], b = id[b];
        g[a][b] = g[b][a] = min(g[a][b], c);
    }
    qmi();
    cout << res[S][E] << '\n';
    return 0;
}