#include<bits/stdc++.h>
using namespace std;
#define FAST                                                                                                           \
    ios::sync_with_stdio(0);                                                                                           \
    cin.tie(0);                                                                                                        \
    cout.tie(0); 

typedef long long ll;
const int N = 1e5 + 10, M = 3e5 + 10;
int n,m;
int h[N],e[M],ne[M],w[M],idx;
int dist[N],cnt[N];
bool st[N];

void add(int a,int b,int c){
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

bool spfa(){
  	memset(dist, 0, sizeof dist);
    memset(cnt, 0, sizeof cnt);
    memset(st, 0, sizeof st);
    stack<int> q;
    st[0] = true;
    q.push(0);
    while (q.size()){
        int t = q.top();
        q.pop();
        st[t] = false;
        for (int i = h[t]; i != -1; i = ne[i]){
            int j = e[i];
            if (dist[j] < dist[t] + w[i]){
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n + 1) return true;
                if (!st[j]){
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
    return false;
}

void solve(){
    memset(h,-1,sizeof(h));
    cin >> n >> m;
    while(m--){
        int op,a,b;
        cin >> op >> a >> b;
        if(op==1) add(a,b,0), add(b,a,0);
        else if(op==2) add(a,b,1);
        else if(op==3) add(b,a,0);
        else if(op==4) add(b,a,1);
        else add(a,b,0);
    }
    for(int i = 1;i<=n;i++) add(0,i,1);
    ll res = 0;
    if(spfa()) res = -1;
    else{
        for(int i = 1;i<=n;i++) res += dist[i];
    }
    cout << res << '\n';
}

int main(){
    FAST
    int T = 1;
    // cin >> T;
    while(T--) solve();
}