#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
typedef long long ll;

int n;
int oil[N], dist[N], q[N];
ll d[N];
bool ans[N];

int main(){
    scanf("%d",&n);
    for(int i = 1;i<=n;i++){
        scanf("%d%d",&oil[i],&dist[i]);
        d[i] = d[i+n] = oil[i] - dist[i];
    }
    for(int i = 1;i<=n*2;i++) d[i] += d[i-1];

    //q[0] =  2 * n + 1;
    int hh = 0, tt = -1;
    for(int i = 2 * n;i>=0;i--){
        if(q[hh]>i+n) hh ++;
        if(i<n&&d[q[hh]]>=d[i]) ans[i+1] = true; 
        while(hh<=tt&&d[q[tt]]>=d[i]) tt--;
        q[++tt] = i;
    }
    
    dist[0] = dist[n];
    for(int i = 1;i<=n;i++){
        d[i] = d[i+n] = oil[i] - dist[i-1];
    }
    for(int i = 1;i<=n*2;i++) d[i] += d[i-1];

    hh = 0, tt = -1;
    //q[0] = 0;
    for(int i = 1; i <= 2 * n; i ++){
        if(q[hh]<i-n) hh ++;
        if(i>n&&d[q[hh]]<=d[i]) ans[i - n] = true; 
        while(hh<=tt&&d[q[tt]]<=d[i]) tt--;
        q[++tt] = i;
    }
    for(int i = 1;i<=n;i++){
        if(ans[i]) puts("TAK");
        else puts("NIE");
    }
}