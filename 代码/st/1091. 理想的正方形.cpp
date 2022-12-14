#include <bits/stdc++.h>
using namespace std;
const int N = 1010, INF = 0x3f3f3f3f;

int n,m,k;
int w[N][N];
int row_min[N][N], row_max[N][N];
int q[N];

void get_min(int a[], int b[], int tot){
    int hh = 0, tt = -1;
    for(int i = 1;i<=tot;i++){
        while(hh<=tt&&q[hh]<i-k+1) hh++;
        while(hh<=tt&&a[q[tt]]>=a[i]) tt--;
        q[++tt] = i;
        b[i] = a[q[hh]];
    }
}

void get_max(int a[], int b[], int tot){
    int hh = 0, tt = -1;
    for(int i = 1;i<=tot;i++){
        if(hh<=tt&&q[hh]<i-k+1) hh++;
        while(hh<=tt&&a[q[tt]]<=a[i]) tt--;
        q[++tt] = i;
        b[i] = a[q[hh]];
    }
}

int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            scanf("%d",&w[i][j]);
        }
    }
    for(int i = 1;i<=n;i++){
        get_min(w[i],row_min[i],m);
        get_max(w[i],row_max[i],m);
    }

    int a[N], b[N], c[N];
    int res = INF;
    for(int i = k;i<=m;i++){
        for(int j = 1;j<=n;j++) a[j] = row_min[j][i];
        get_min(a,b,n);
        for(int j = 1;j<=n;j++) a[j] = row_max[j][i];
        get_max(a,c,n);
        for(int j = k;j<=n;j++) res = min(res,c[j] - b[j]);
    }
    printf("%d\n",res);
}