#include <bits/stdc++.h>
using namespace std;
const int N = 100010, M = 2000010, INF = 0x3f3f3f3f;

int n,m;
int h[N],rh[N],e[M],ne[M],idx;
int dmin[N],dmax[N];
int price[N];
bool st[N];

void add(int *h,int a,int b){
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void spfa(int *d,int start,int *h,bool flag){
    queue<int> q;
    memset(st,false,sizeof(st));
    if(flag) memset(d,0x3f,sizeof(dmin));
    q.push(start);
    st[start] = true;
    d[start] = price[start];
    while(q.size()){
        int t = q.front();
        q.pop();
        st[t] = false;
        for(int i = h[t];~i;i=ne[i]){
            int j = e[i];
            if(flag&&d[j]>min(d[t],price[j])||!flag&&d[j]<max(d[t],price[j])){
                if(flag) d[j] = min(d[t],price[j]);
                else d[j] = max(d[t],price[j]);
                if(!st[j]){
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
}

int main(){
    memset(h,-1,sizeof(h));
    memset(rh,-1,sizeof(rh));
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++) scanf("%d",&price[i]);
    while(m--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        add(h,a,b), add(rh,b,a);
        if(c==2) add(h,b,a), add(rh,a,b);
    }
    spfa(dmin,1,h,true);
    spfa(dmax,n,rh,false);
    int res = 0;
    for(int i = 1;i<=n;i++) res = max(res,dmax[i]-dmin[i]);
    printf("%d\n",res);
}