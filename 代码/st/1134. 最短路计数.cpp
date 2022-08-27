#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, M = 4e5 + 10, mod = 100003;

int n,m;
int h[N],e[M],w[M],ne[M],idx;
int dist[N], cnt[N];
int q[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

void bfs(){
    memset(dist,0x3f,sizeof(dist));
    dist[1] = 0;
    cnt[1] = 1;
    int hh = 0, tt = 0;
    q[0] = 1;
    while(hh<=tt){
        int t = q[hh++];
        for(int i = h[t];~i;i=ne[i]){
            int j = e[i];
            if(dist[j]>dist[t]+1){
                dist[j] = dist[t] + 1;
                cnt[j] = cnt[t];
                q[++tt] = j;
            }
            else if(dist[j]==dist[t]+1){
                cnt[j] = (cnt[t] + cnt[j]) % mod;
            }
        }
    }
}

int main(){
    memset(h,-1,sizeof(h));
    cin >> n >> m;
    while(m--){
        int a,b;
        cin >> a >> b;
        add(a,b,1), add(b,a,1);
    }
    bfs();
    for(int i = 1;i<=n;i++) cout << cnt[i] << endl;
}