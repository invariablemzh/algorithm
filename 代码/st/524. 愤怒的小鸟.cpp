#include <bits/stdc++.h>
using namespace std;
const int N = 18, M = 1 << 18;
const double eps = 1e-8;

typedef pair<double,double> PDD;
#define x first
#define y second

int n,m;
PDD q[N];
int path[N][N],f[M];

int cmp(double x, double y){
    if(fabs(x-y)<eps) return 0;
    if(x<y) return -1;
    return 1;
}

int main(){
    int T; scanf("%d",&T);
    while(T--){
        memset(path,0,sizeof(path));
        scanf("%d%d",&n,&m);
        for(int i = 0;i<n;i++){
            scanf("%lf%lf",&q[i].x, &q[i].y);
        }
        for(int i = 0;i<n;i++){
            path[i][i] = 1 << i;
            for(int j = 0;j<n;j++){
                double x1 = q[i].x, y1 = q[i].y;
                double x2 = q[j].x, y2 = q[j].y;
                if(!cmp(x1,x2)) continue;
                double a = (y1/x1-y2/x2)/(x1-x2);
                double b = (y1/x1-a*x1);
                if(cmp(a,0)>=0) continue; 
                int state = 0;
                for(int k = 0;k<n;k++){
                    double x = q[k].x, y = q[k].y;
                    if(!cmp(a * x * x + b * x,y)) state += 1 << k;
                }
                path[i][j] = state;
            }
        }

        memset(f,0x3f,sizeof(f));
        f[0] = 0;
        for(int i = 0;i+1<1<<n;i++){
            int x = 0;
            for(int j = 0;j<n;j++){
                if(!(i>>j&1)){
                    x = j;
                    break;
                }
            }
            for(int j = 0;j<n;j++){
                f[i|path[x][j]] = min(f[i|path[x][j]],f[i]+1);
            }
        }
        printf("%d\n",f[(1<<n)-1]);
    }
}