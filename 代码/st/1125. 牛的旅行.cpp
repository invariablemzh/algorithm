#include <bits/stdc++.h>
using namespace std;
const int N = 160, INF = 1e9;
typedef pair<int,int> PII;
#define x first
#define y second

int n;
PII q[N];
double d[N][N], maxd[N];
char g[N][N];

double get(PII a, PII b){
    double dx = a.x - b.x;
    double dy = a.y - b.y;
    return sqrt(dx * dx + dy * dy);
}

int main(){
    scanf("%d",&n);
    for(int i = 1;i<=n;i++) scanf("%d%d",&q[i].x, &q[i].y);
    for(int i = 1;i<=n;i++) scanf("%s",g[i] + 1);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(i==j) d[i][j] = 0;
            else if(g[i][j]=='1') d[i][j] = get(q[i],q[j]);
            else d[i][j] = INF;
        }
    }
    for(int k = 1;k<=n;k++){
        for(int i = 1;i<=n;i++){
            for(int j = 1;j<=n;j++){
                d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
            }
        }
    }
    double r1 = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(d[i][j] < INF) maxd[i] = max(maxd[i],d[i][j]);
        }
        r1 = max(r1,maxd[i]);
    }
    double r2 = INF;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            if(d[i][j]>INF/2){
                r2 = min(r2,maxd[i] + maxd[j] + get(q[i],q[j]));
            }
        }
    }
    printf("%lf\n",max(r1,r2));
}