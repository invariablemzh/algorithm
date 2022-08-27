#include <bits/stdc++.h>
using namespace std;
const int N = 1010, M = 20010;

int n,m,K;
int h[N],e[M],w[M],ne[M],idx;
int dist[N];
bool st[N];
deque<int> q;

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool check(int bound){
    memset(dist,0x3f,sizeof(dist));
    memset(st,false,sizeof(st));
    dist[1] = 0;
    q.push_front(1);
    while(q.size()){
        int t = q.front();
        q.pop_front();
        if(st[t]) continue;
        st[t] = true;
        for(int i = h[t];~i;i=ne[i]){
            int j = e[i], x = w[i] > bound;
            if(dist[j]>dist[t]+x){
                dist[j] = dist[t] + x;
                if(!x) q.push_front(j);
                else q.push_back(j);
            }
        }
    }
    return dist[n] <= K;
}

int main(){
    memset(h,-1,sizeof(h));
    cin >> n >> m >> K;
    while(m--){
        int a,b,c;
        cin >> a >> b >> c;
        add(a,b,c), add(b,a,c);
    }
    int l = 0, r = 1e6 + 1;
    while(l<r){
        int mid = l + r >> 1;
        if(check(mid)) r = mid;
        else l = mid + 1;
    }
    if(r==1e6+1) puts("-1");
    else printf("%d\n",r);
}